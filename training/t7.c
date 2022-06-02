// Introduction to semaphores in C
// !!! sem_init and sem_destoy deprecated !!! -> sem_open, sem_close

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t	semaphore;

void	*routine(void *arg)
{
	sem_wait(&semaphore);
	sleep(1);
	printf("Hello from thread %d\n", *(int*)arg);
	sem_post(&semaphore);
	free(arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[4];

	sem_init(&semaphore, 0, 1);
	for (int i = 0 ; i < 4 ; i++)
	{
		int	*a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	sem_destroy(&semaphore);
	return (0);
}

// sem_wait ~= mutex_lock
// sem_post ~= mutex_unlock
//
// sem_wait check s value
// if s == 0 -> wait
// if s > 0  -> s--
//
// sem_post  -> s++
