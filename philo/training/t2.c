

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("Got lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
}

int	main(int argc, char **argv)
{
	pthread_t	th[4];

	pthread_mutex_init(&mutex, NULL);
	for (int i = 0 ; i < 4 ; i++)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
			return (1);
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
	}
	pthread_mutex_destroy(&mutex);
}

