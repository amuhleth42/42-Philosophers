/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:17:57 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 22:20:07 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, t_data *a)
{
	pthread_mutex_lock(&a->forks[philo->nb]);
	print_log(philo, a, FORK);
	if (philo->nb == a->nb_philo - 1)
		pthread_mutex_lock(&a->forks[0]);
	else
		pthread_mutex_lock(&a->forks[philo->nb + 1]);
	print_log(philo, a, FORK);
}

void	unlock_forks(t_philo *philo, t_data *a)
{
	pthread_mutex_unlock(&a->forks[philo->nb]);
	if (philo->nb == a->nb_philo - 1)
		pthread_mutex_unlock(&a->forks[0]);
	else
		pthread_mutex_unlock(&a->forks[philo->nb + 1]);
}

void	eat(t_philo *philo, t_data *a)
{
	print_log(philo, a, EAT);
	gettimeofday(&philo->last_meal, NULL);
	usleep(a->time_to_eat);
	philo->meal_count++;
}

void	philo_sleep(t_philo *philo, t_data *a)
{
	print_log(philo, a, SLEEP);
	usleep(a->time_to_sleep);
	print_log(philo, a, THINK);
}

void	*routine_philo(void *arg)
{
	t_data	*a;
	t_philo	*philo;

	philo = arg;
	a = philo->backup;
	if (philo->nb % 2 != 0)
		usleep(800);
	gettimeofday(&philo->last_meal, NULL);
	while (1)
	{
		take_forks(philo, a);
		eat(philo, a);
		unlock_forks(philo, a);
		if (philo->meal_count == a->loop)
		{
			philo->done = 1;
			a->count_done++;
			break ;
		}
		philo_sleep(philo, a);
	}
	return (NULL);
}
