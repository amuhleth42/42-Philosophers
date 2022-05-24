/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:43:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/24 15:00:09 by amuhleth         ###   ########.fr       */
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
	pthread_t	tid;
	int			nb;
	int			eat_done;
	int			sleep_done;
	int			is_dead;
	t_data		*backup;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				loop;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_t		checker;
	struct timeval	start;
	int				timestamp;
}					t_data;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	print_log(t_philo *philo, t_data *a, int cmd);

void	get_timestamp(t_data *a);

#endif
