// Recursive mutexes

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t	mutex_fuel;
int	fuel = 50;

void	*routine(void *arg)
{
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	fuel += 50;
	printf("Incremented fuel to %d\n", fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	th[8];
	pthread_mutexattr_t	recursive_mutex_attr;
	int	i;

	pthread_mutexattr_init(&recursive_mutex_attr);
	pthread_mutexattr_settype(&recursive_mutex_attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex_fuel, &recursive_mutex_attr);
	for (i = 0 ; i < 8 ; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}
	for (i = 0 ; i < 8 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	printf("Fuel: %d\n", fuel);
	pthread_mutexattr_destroy(&recursive_mutex_attr);
	pthread_mutex_destroy(&mutex_fuel);
	return (0);
}
