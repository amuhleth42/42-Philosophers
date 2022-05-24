/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:19:41 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/24 20:48:34 by amuhleth         ###   ########.fr       */
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

void	*checker_routine(void *arg)
{
	t_data	*a;
	t_philo	*philo;
	int		i;
	int		time;

	philo = arg;
	a = philo->backup;
	i = 0;
	while (1)
	{
		time = get_time_diff(&a->philo[i]);
		if (time >= a->time_to_die)
		{
			a->one_is_dead = 1;
			print_log(&a->philo[i], a, DIED);
			detach_all(a);
			break ;
		}
		i++;
		if (i == a->nb_philo)
			i = 0;
	}
	return (NULL);
}
