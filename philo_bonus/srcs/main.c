/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/02 19:56:17 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_semaphores(t_data *a)
{
	sem_close(a->forks);
	sem_close(a->writing);
}

void	process(t_data *a)
{
	a->pid = ft_calloc(a->nb_philo + 1, sizeof(pid_t));
	if (!a->pid)
		die("Malloc error\n");
	init_semaphore(a);
	gettimeofday(&a->start, NULL);
	start_processes(a);
	//pthread_join(a->checker, NULL);
	free(a->pid);
	close_semaphores(a);
}

int	main(int argc, char **argv)
{
	t_data	a;

	ft_bzero(&a, sizeof(t_data));
	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		return (1);
	}
	a.nb_philo = ft_atoi(argv[1]);
	a.time_to_die = ft_atoi(argv[2]);
	a.time_to_eat = 1000 * ft_atoi(argv[3]);
	a.time_to_sleep = 1000 * ft_atoi(argv[4]);
	if (argc == 6)
		a.loop = ft_atoi(argv[5]);
	process(&a);
	return (0);
}
