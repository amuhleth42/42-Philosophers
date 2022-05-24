/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:38:12 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/24 14:49:09 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_timestamp(t_data *a)
{
	struct timeval	now;
	double			sec;
	double			usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - a->start.tv_sec;
	usec = now.tv_usec - a->start.tv_usec;
	a->timestamp = sec * 1000 + usec / 1000;
}
