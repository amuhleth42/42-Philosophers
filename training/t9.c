// Practical example using semaphores (Login Queue)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void	*routine(void *args)
{
	sem_t	*semaphore;
	semaphore = args;
	printf("Waiting in the login queue\n");
	sleep(1);
	sem_wait(semaphore);
	printf("Logged in\n");
	sleep(rand() % 5 + 1);
	printf("Logged out\n");
	sem_post(semaphore);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[8];
	sem_t		*semaphore;

	sem_unlink("/sem");
	semaphore = sem_open("/sem", O_CREAT, 0664, 3);
	if (semaphore == SEM_FAILED)
		perror("Failed to open semaphore");
	
	for (int i = 0 ; i < 8 ; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, semaphore) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0 ; i < 8 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	return (0);
}
