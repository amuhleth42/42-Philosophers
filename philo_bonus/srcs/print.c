/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:00 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/03 19:30:47 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_log(t_data *a, int cmd)
{
	sem_wait(a->writing);
	a->timestamp = get_timestamp(a);
	printf("%7d ms    philo nb %-3d ", a->timestamp, a->philo.nb + 1);
	if (cmd == FORK)
		printf("has taken a fork\033[0m\n");
	else if (cmd == EAT)
		printf("is eating\033[0m, %d\n", a->philo.meal_count + 1);
	else if (cmd == SLEEP)
		printf("is sleeping\033[0m\n");
	else if (cmd == THINK)
		printf("is thinking\033[0m\n");
	else if (cmd == DIED)
		printf("died\033[0m\n");
	if (cmd != DIED)
		sem_post(a->writing);
}

/*void	print_log(t_data *a, int cmd)
{
	sem_wait(a->writing);
	a->timestamp = get_timestamp(a);
	printf("%7d ms    philo nb %-3d ", a->timestamp, a->philo.nb + 1);
	if (cmd == FORK)
		printf("\033[0;33mhas taken a fork\033[0m\n");
	else if (cmd == EAT)
		printf("\033[0;32mis eating\033[0m, %d\n", a->philo.meal_count + 1);
	else if (cmd == SLEEP)
		printf("\033[0;34mis sleeping\033[0m\n");
	else if (cmd == THINK)
		printf("\033[0;35mis thinking\033[0m\n");
	else if (cmd == DIED)
		printf("\033[0;31mdied\033[0m\n");
	if (cmd != DIED)
		sem_post(a->writing);
}*/
