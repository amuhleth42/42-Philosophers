/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/02 19:07:46 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philo(t_data *a)
{
	free(a->philo);
}

void	process(t_data *a)
{
	init_philo(a);
	init_semaphore(a);
	gettimeofday(&a->start, NULL);
	start_processes(a);
	pthread_join(a->checker, NULL);
	free_philo(a);
	destroy_mutex(a);
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
