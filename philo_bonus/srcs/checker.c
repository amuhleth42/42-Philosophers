/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:35:51 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/03 16:57:39 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	checker(t_data *a)
{
	int	time;

	while (1)
	{
		gettimeofday(&a->check_time, NULL);
		usleep(2500);
		time = get_time_diff(&a->philo, &a->check_time);
		if (time >= a->time_to_die && a->philo.done)
		{
			print_log(a, DIED);
			sem_post(a->died);
			break ;
		}
		if (a->count_done == a->nb_philo)
		{
			sem_post(a->done);
			break ;
		}
	}
}

void	*checker_routine(void *arg)
{
	t_data	*a;

	a = arg;
	checker(a);
	return (NULL);
}
