/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:08:20 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/03 19:16:23 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphore(t_data *a)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_writing");
	sem_unlink("/sem_died");
	sem_unlink("/sem_done");
	a->forks = sem_open("/sem_forks", O_CREAT, 0664, a->nb_philo);
	a->writing = sem_open("/sem_writing", O_CREAT, 0664, 1);
	a->died = sem_open("/sem_died", O_CREAT, 0664, 0);
	a->done = sem_open("/sem_done", O_CREAT, 0664, 0);
	if (a->forks == SEM_FAILED || a->writing == SEM_FAILED)
		die("Failed to open semaphore\n");
	if (a->died == SEM_FAILED || a->done == SEM_FAILED)
		die("Failed to open semaphore\n");
}

void	start_processes(t_data *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		a->philo.nb = i;
		a->pid[i] = fork();
		if (a->pid[i] == 0)
			routine_philo(a);
		i++;
	}
}
