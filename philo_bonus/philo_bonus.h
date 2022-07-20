/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:48:27 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/20 17:53:18 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

typedef struct s_philo
{
	pthread_t		tid;
	int				nb;
	struct timeval	last_meal;
	int				meal_count;
	int				done;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				loop;
	int				count_done;
	pid_t			*pid;
	t_philo			philo;
	sem_t			*forks;
	sem_t			*writing;
	sem_t			*died;
	sem_t			*done;
	pthread_t		check_died;
	pthread_t		check_all_done;
	struct timeval	start;
	struct timeval	check_time;
	int				timestamp;
	int				one_died;
	int				all_done;
}					t_data;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	die(char *s);

void	init_semaphore(t_data *a);
void	start_processes(t_data *a);

void	print_log(t_data *a, int cmd);

int		get_timestamp(t_data *a);
int		get_time_diff(t_philo *philo, struct timeval *checktime);
int		ft_usleep(int usec);

void	routine_philo(t_data *a);

void	*checker_routine(void *arg);
void	*check_died(void *arg);
void	*check_all_done(void *arg);

#endif
