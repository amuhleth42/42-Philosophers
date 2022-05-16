
#include "philo.h"


void	*routine(void *arg)
{
	t_data	*a;
	t_philo	*philo;
	philo = arg;
	a = philo->backup;
	printf("Yo moi c'est %d/%d\n", philo->nb, a->nb_philo);

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
		pthread_create(&a->philo[i].tid, NULL, &routine, &a->philo[i]);
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

void	free_philo(t_data *a)
{
	free(a->philo);
	free(a->forks);
}

void	process(t_data *a)
{
	init_philo(a);
	start_threads(a);


	free_philo(a);
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
