/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:43:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/06/01 19:43:54 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

typedef struct s_data t_data;

typedef struct s_philo
{
	pthread_t		tid;
	int				nb;
	struct timeval	last_meal;
	int				meal_count;
	int				done;
	t_data			*backup;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				loop;
	int				count_done;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_t		checker;
	struct timeval	start;
	struct timeval	check_time;
	int				timestamp;
}					t_data;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	init_philo(t_data *a);
void	init_mutex(t_data *a);
void	start_threads(t_data *a);

void	*routine_philo(void *arg);

void	*checker_routine(void *arg);
void	detach_all(t_data *a);

void	print_log(t_philo *philo, t_data *a, int cmd);

int		get_timestamp(t_data *a);
int		get_time_diff(t_philo *philo, struct timeval *check_time);

#endif
