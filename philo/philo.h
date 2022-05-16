
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>

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
}					t_data;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
