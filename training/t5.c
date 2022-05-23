// Introduction to barriers

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t	barrier;

void	*routine(void *arg)
{
	printf("Waiting at the barrier...\n");
	pthread_barrier_wait(&barrier);
	printf("We passed the barrier\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	th[2];

	pthread_barrier_init(&barrier, NULL, 3);
	for (int i = 0; i < 2 ; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0 ; i < 2 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	pthread_barrier_destroy(&barrier);
	return (0);
}


// pthread_barrier not supported in MacOS!
