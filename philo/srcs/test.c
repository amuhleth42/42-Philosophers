/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:43:25 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 18:39:42 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *a)
{
	int	i;

	pthread_mutex_destroy(&a->writing);
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_mutex_destroy(&a->forks[i]);
		i++;
	}
}

void	free_philo(t_data *a)
{
	free(a->philo);
	free(a->forks);
}

void	process(t_data *a)
{
	init_philo(a);
	init_mutex(a);
	gettimeofday(&a->start, NULL);
	start_threads(a);
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
