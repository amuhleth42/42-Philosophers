/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:38:12 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 19:28:42 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp(t_data *a)
{
	struct timeval	now;
	double			sec;
	double			usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - a->start.tv_sec;
	usec = now.tv_usec - a->start.tv_usec;
	return (sec * 1000 + usec / 1000);
}

int	get_time_diff(t_philo *philo, struct timeval *check_time)
{
	double	sec;
	double	usec;

	sec = check_time->tv_sec - philo->last_meal.tv_sec;
	usec = check_time->tv_usec - philo->last_meal.tv_usec;
	return (sec * 1000 + usec / 1000);
}
