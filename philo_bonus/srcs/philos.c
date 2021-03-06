/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:43:38 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/20 17:59:02 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_data *a)
{
	sem_wait(a->forks);
	print_log(a, FORK);
	sem_wait(a->forks);
	print_log(a, FORK);
}

void	unlock_forks(t_data *a)
{
	sem_post(a->forks);
	sem_post(a->forks);
}

void	eat(t_data *a)
{
	print_log(a, EAT);
	gettimeofday(&a->philo.last_meal, NULL);
	ft_usleep(a->time_to_eat);
	a->philo.meal_count++;
}

void	philo_sleep(t_data *a)
{
	print_log(a, SLEEP);
	ft_usleep(a->time_to_sleep);
	print_log(a, THINK);
}

void	routine_philo(t_data *a)
{
	if (a->philo.nb % 2 != 0)
		usleep(800);
	if (pthread_create(&a->philo.tid, NULL, &checker_routine, a) != 0)
	{
		sem_post(a->done);
		pause();
	}
	gettimeofday(&a->philo.last_meal, NULL);
	while (1)
	{
		take_forks(a);
		eat(a);
		unlock_forks(a);
		if (a->philo.meal_count == a->loop)
		{
			a->philo.done = 1;
			sem_post(a->done);
			break ;
		}
		philo_sleep(a);
	}
	pause();
}
