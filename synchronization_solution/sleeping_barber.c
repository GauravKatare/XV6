#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<semaphore.h>
sem_t cust,barb,mutex,cut;
int seats;

void * barber(void * arg)
{
	while(1)
	{
		sem_wait(&cust);
		sem_post(&barb);
		sem_wait(&cut);
	}
}

void * customer(void * arg)
{
	int t = (int) arg;
	printf("Customer %d arrived\n",t);
	sem_wait(&mutex);
	if(seats==0)
	{
		printf("Customer %d leaving\n",t);
		sem_post(&mutex);
		pthread_exit(0);
	}
	seats--;
	sem_post(&mutex);
	sem_post(&cust);
	sem_wait(&barb);
	sem_wait(&mutex);
	seats++;
	sem_post(&mutex);
	printf("Customer %d getting haircut\n",t);
	sleep(4);
	printf("Customer %d done getting haircut\n",t);
	sem_post(&cut);
	pthread_exit(0);
}

int main()
{
	pthread_t t;
	sem_init(&cust,0,0);
	sem_init(&barb,0,0);
	sem_init(&mutex,0,1);
	sem_init(&cut,0,0);
	pthread_create(&t,NULL,barber,NULL);
	int i=1;
	seats = 6;
	while(1)
	{
		pthread_create(&t,NULL,customer,(void*)(i++));
		sleep(1);
	}

}