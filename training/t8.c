// Introduction to semaphores in C
// but with sem_open and sem_close

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

void	*routine(void *arg)
{
	sem_t	*semaphore;

	semaphore = arg;
	sem_wait(semaphore);
	sleep(1);
	printf("Hello from thread\n");
	sem_post(semaphore);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[10];
	sem_t		*sem;

	sem_unlink("/sem");
	sem = sem_open("/sem", O_CREAT, 0660, 3);
	if (sem == SEM_FAILED)
		perror("Failed to open semaphore");

	for (int i = 0 ; i < 10 ; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, sem) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	sem_close(sem);
	return (0);
}

// it works !!!!!
