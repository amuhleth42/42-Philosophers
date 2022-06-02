/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:00 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/02 18:53:25 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
}
