#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<semaphore.h>

sem_t mutex[5];

void * threadex(void * arg)
{
	int t = (int) arg;
	int f = (t+1)%5;
	int o = t;
	if(t%2==1)
	{
		t^=f^=t^=f;	
	}

	sem_wait(&mutex[t]);
	sem_wait(&mutex[f]);
	printf("%d eating\n",o);
	printf("%d done eating\n",o);
	sleep(1);
	
	sem_post(&mutex[t]);
	sem_post(&mutex[f]);
	pthread_exit(NULL);
}


int main()
{
	pthread_t arr[5];
	for(int i=0;i<5;i++)
		sem_init(&mutex[i],0,1);
	for(int i=0;i<5;i++)
	{
		pthread_create(&arr[i],NULL,threadex,(void*)i);
	}
	for(int i=0;i<5;i++)
		pthread_join(arr[i],NULL);
}