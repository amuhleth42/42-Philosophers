
#include "philo.h"

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
}
