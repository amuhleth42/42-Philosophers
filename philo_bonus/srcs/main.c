/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/03 16:45:05 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_semaphores(t_data *a)
{
	sem_close(a->forks);
	sem_close(a->writing);
	sem_close(a->died);
	sem_close(a->done);
}

void	*check_died(void *arg)
{
	t_data	*a;

	a = arg;
	sem_wait(a->died);
	a->one_died = 1;
	return (NULL);
}

void	*check_all_done(void *arg)
{
	t_data	*a;
	int		i;

	a = arg;
	i = 0;
	while (i < a->nb_philo)
	{
		sem_wait(a->done);
		i++;
	}
	a->all_done = 1;
	return (NULL);
}

void	process(t_data *a)
{
	int	i;

	a->pid = ft_calloc(a->nb_philo + 1, sizeof(pid_t));
	if (!a->pid)
		die("Malloc error\n");
	init_semaphore(a);
	gettimeofday(&a->start, NULL);
	start_processes(a);
	if (pthread_create(&a->check_died, NULL, &check_died, a) != 0)
		exit(EXIT_FAILURE);
	if (pthread_create(&a->check_all_done, NULL, &check_died, a) != 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (!a->all_done || !a->one_died)
		usleep(200);
	while (i < a->nb_philo)
		kill(a->pid[i], SIGKILL);
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
