// Practical example for pthread_mutex_trylock

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// chefs = threads
// stove = shared data (+mutex)

pthread_mutex_t	stove_mutex[4];
int	stove_fuel[4] = { 100, 100, 100, 100 };

void	*routine(void *args)
{
	int	fuel_needed;

	for (int i = 0 ; i < 4 ; i++)
	{
		if (pthread_mutex_trylock(&stove_mutex[i]) == 0)
		{
			fuel_needed = (rand() & 20);
			if (stove_fuel[i] - fuel_needed < 0)
				printf("No more fuel...\n");
			else
			{
				stove_fuel[i] -= fuel_needed;
				printf("Fuel left in %d: %d\n", i, stove_fuel[i]);
			}
			usleep(500000);
			pthread_mutex_unlock(&stove_mutex[i]);
			break ;
		}
		else
		{
			if (i == 3)
			{
				printf("No stove available yet, waiting...\n");
				usleep(300000);
				i = 0;
			}
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];

	srand(time(NULL));
	for (int i = 0 ; i < 4 ; i++)
		pthread_mutex_init(&stove_mutex[i], NULL);

	for (int i = 0 ; i < 10 ; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	for (int i = 0 ; i < 4 ; i++)
		pthread_mutex_destroy(&stove_mutex[i]);
	return (0);
}
