

int	lock;

lock = 0;

// in the thread function
{
	if (lock == 1)
		//wait until lock == 0
	lock = 1;
	//use your variable (ex : x)
	x++;
	lock = 0;
}

//same thing with mutex

pthread_mutex_t	mutex;

pthread_mutex_init(&mutex, NULL);

// in the thread function
{
	pthread_mutex_lock(&mutex);
	//use your variable :
	x++;
	pthread_mutex_unlock(&mutex);
}

pthread_mutex_destroy(&mutex);

// so, this...

if (lock == 1)
	//wait until lock == 0
lock = 1;

// equals this.

pthread_mutex_lock(&mutex);

//so the mutex is the lock
// the mutex should be in my global structure
// mais du coup est-ce que j'ai besoin d'avoir une variable fork, ou seulement un mutex?
// seulement un mutex je pense?
