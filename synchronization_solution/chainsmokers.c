#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<stdlib.h>

sem_t agent,p,t,m,mutex;

int tob,mat,pap;

void * agentex(void *arg)
{
	while(1)
	{
		sem_wait(&agent);
		sem_wait(&mutex);
		int tr = rand()%3;
		if(tr==0)
		{
			printf("Putting Matches and paper\n");
			mat++;
			pap++;
			sem_post(&t);
		}
		if(tr==1)
		{
			printf("Putting paper and tobacco\n");
			tob++;
			pap++;	
			sem_post(&m);
		}
		if(tr==2)
		{
			printf("Putting tobacco and Matches\n");
			tob++;
			mat++;
			sem_post(&p);
		}
		sem_post(&mutex);
	}
}

char * stat[] = {"Tobacco man","Matches man","Paper man"};

void * threadex(void * arg)
{
	int o = (int) arg;
	while(1)
	{
		if(o==0)
		sem_wait(&t);
		if(o==1)
		sem_wait(&m);
		if(o==2)
		sem_wait(&p);
		sem_wait(&mutex);
		printf("%s Smoking <<<<<<<<<<<<<<<<:::::::::>>>>>>>>>>>>\n",stat[o]);
		sleep(1);
		sem_post(&mutex);
		sem_post(&agent);
	}
}

int main()
{
	srand(time(0));
	sem_init(&agent,0,1);
	sem_init(&mutex,0,1);
	sem_init(&t,0,0);
	sem_init(&m,0,0);
	sem_init(&p,0,0);
	pthread_t a,tr[3];
	pthread_create(&a,0,agentex,0);
	for(int i=0;i<3;i++)
		pthread_create(&tr[i],0,threadex,(void*)i);
	pthread_join(a,0);
	for(int i=0;i<3;i++)
		pthread_join(tr[i],0);
	return 0;
}
