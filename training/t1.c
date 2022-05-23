// sum an array using threads


#include <pthreads.h>


int	primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	i;
	int	sum;

	i = *(int *)arg;
	sum = 0;
	for (int j = 0; j < 5 ; j++)
	{
		sum += primes[i + j];
	}
	*(int *)arg = sum;
	return (arg);
}

int	main(int argc, char **argv)
{
	pthread_t	th[2];
	int			i;
	int			*a;
	int			*small_sum;
	int			result;

	i = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int));
		a = i * 5;
		if (pthread_create(th + i, NULL, &routine, a) != 0)
			return (1);
		i++;
	}
	result = 0;
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], &small_sum) != 0)
			return (2);
		i++;
		result += *small_sum;
		free(small_sum);
	}
}
