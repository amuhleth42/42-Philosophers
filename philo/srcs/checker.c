/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:19:41 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 19:52:07 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_all(t_data *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		pthread_detach(a->philo[i].tid);
		i++;
	}
}

void	checker(t_data *a, t_philo *philo)
{
	int	i;
	int	time;

	i = 0;
	while (1)
	{
		gettimeofday(&a->check_time, NULL);
		usleep(3500);
		time = get_time_diff(&a->philo[i], &a->check_time);
		if (time >= a->time_to_die && !philo[i].done)
		{
			print_log(&a->philo[i], a, DIED);
			detach_all(a);
			break ;
		}
		if (a->count_done == a->nb_philo)
			break ;
		i++;
		if (i == a->nb_philo)
			i = 0;
	}
}

void	*checker_routine(void *arg)
{
	t_data	*a;
	t_philo	*philo;

	philo = arg;
	a = philo->backup;
	checker(a, philo);
	return (NULL);
}
