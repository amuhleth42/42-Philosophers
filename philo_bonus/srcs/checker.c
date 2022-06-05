/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:35:51 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/05 10:55:39 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	checker(t_data *a)
{
	int	time;

	while (1)
	{
		gettimeofday(&a->check_time, NULL);
		usleep(2500);
		time = get_time_diff(&a->philo, &a->check_time);
		if (time >= a->time_to_die && !a->philo.done)
		{
			print_log(a, DIED);
			sem_post(a->died);
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
