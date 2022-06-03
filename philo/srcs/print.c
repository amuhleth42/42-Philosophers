/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:59 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/03 19:32:55 by amuhleth         ###   ########.fr       */
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
		printf("is eating, %d\n", philo->meal_count + 1);
	else if (cmd == SLEEP)
		printf("is sleeping\n");
	else if (cmd == THINK)
		printf("is thinking\n");
	else if (cmd == DIED)
		printf("died\n");
	if (cmd != DIED)
		pthread_mutex_unlock(&a->writing);
}
/*
void	print_log(t_philo *philo, t_data *a, int cmd)
{
	pthread_mutex_lock(&a->writing);
	a->timestamp = get_timestamp(a);
	printf("%7d ms    philo nb %-3d ", a->timestamp, philo->nb + 1);
	if (cmd == FORK)
		printf("\033[0;33mhas taken a fork\n");
	else if (cmd == EAT)
		printf("\033[0;32mis eating, %d\n", philo->meal_count + 1);
	else if (cmd == SLEEP)
		printf("\033[0;34mis sleeping\n");
	else if (cmd == THINK)
		printf("\033[0;35mis thinking\n");
	else if (cmd == DIED)
		printf("\033[0;31mdied\n");
	printf("\033[0m");
	if (cmd != DIED)
		pthread_mutex_unlock(&a->writing);
}*/
