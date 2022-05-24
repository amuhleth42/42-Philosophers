/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:59 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/24 19:24:46 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *philo, t_data *a, int cmd)
{
	pthread_mutex_lock(&a->writing);
	a->timestamp = get_timestamp(a);
	printf("%7d ms    philo nb %-3d ", a->timestamp, philo->nb + 1);
	if (cmd == FORK)
		printf("has taken a fork\n");
	else if (cmd == EAT)
		printf("is eating\n");
	else if (cmd == SLEEP)
		printf("is sleeping\n");
	else if (cmd == THINK)
		printf("is thinking\n");
	else if (cmd == DIED)
		printf("died\n");
	pthread_mutex_unlock(&a->writing);
}
