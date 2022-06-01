/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:14:59 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 16:11:28 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *a)
{
	a->philo = ft_calloc(a->nb_philo + 1, sizeof(t_philo));
	a->forks = ft_calloc(a->nb_philo + 1, sizeof(pthread_mutex_t));
}

void	init_mutex(t_data *a)
{
	int	i;

	pthread_mutex_init(&a->writing, NULL);
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_mutex_init(&a->forks[i], NULL);
		i++;
	}
}

void	start_threads(t_data *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		a->philo[i].backup = a;
		a->philo[i].nb = i;
		if (pthread_create(&a->philo[i].tid, NULL,
				&routine_philo, &a->philo[i]) != 0)
			perror("Aiieeeeeee");
		i++;
	}
	if (pthread_create(&a->checker, NULL, &checker_routine, &a->philo[0]) != 0)
		perror("Aiieeeeeee");
}
