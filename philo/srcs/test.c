/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:43:25 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/24 15:33:48 by amuhleth         ###   ########.fr       */
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
	usleep(a->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo, t_data *a)
{
	print_log(philo, a, SLEEP);
	usleep(a->time_to_sleep * 1000);
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
	while (!philo->is_dead)
	{
		take_forks(philo, a);
		eat(philo, a);
		unlock_forks(philo, a);
		philo_sleep(philo, a);
	}

	return (NULL);
}

void	start_threads(t_data *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		a->philo[i].backup = a;
		a->philo[i].nb = i;
		pthread_create(&a->philo[i].tid, NULL, &routine_philo, &a->philo[i]);
		i++;
	}
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_join(a->philo[i].tid, NULL);
		i++;
	}
}

void	init_philo(t_data *a)
{
	a->philo = ft_calloc(a->nb_philo + 1, sizeof(t_philo));
	a->forks = ft_calloc(a->nb_philo + 1, sizeof(pthread_mutex_t));
}

void	init_mutex(t_data *a)
{
	int	i;

	pthread_mutex_init(&a->writing, NULL);
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_mutex_init(&a->forks[i], NULL);
		i++;
	}
}

void	destroy_mutex(t_data *a)
{
	int	i;

	pthread_mutex_destroy(&a->writing);
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_mutex_destroy(&a->forks[i]);
		i++;
	}
}

void	free_philo(t_data *a)
{
	free(a->philo);
	free(a->forks);
}

void	process(t_data *a)
{
	init_philo(a);
	init_mutex(a);
	gettimeofday(&a->start, NULL);
	start_threads(a);


	free_philo(a);
	destroy_mutex(a);
}

int	main(int argc, char **argv)
{
	t_data	a;

	ft_bzero(&a, sizeof(t_data));
	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		return (1);
	}
	a.nb_philo = ft_atoi(argv[1]);
	a.time_to_die = ft_atoi(argv[2]);
	a.time_to_eat = ft_atoi(argv[3]);
	a.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		a.loop = ft_atoi(argv[5]);
	process(&a);
	return (0);
}
