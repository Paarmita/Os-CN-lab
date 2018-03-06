#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;
int n=0;

void* even()
{
	pthread_mutex_lock(&lock);
	do
	{
		if(n%2==0)
		{
			printf(" %d ",n);
			n++;
		}
		else
		{        
			pthread_mutex_unlock(&lock);
		}
	}
	while(n<100);
}

void* odd()
{
	pthread_mutex_lock(&lock);
	do
	{
		if(n%2!=0)
		{
			printf("\n %d ",n);
			n++;
		}
		else
		{        
			pthread_mutex_unlock(&lock);
		}
	}
	while(n<100);
}

int main()
{
	pthread_t pid,tid;
	int rv=pthread_mutex_init(&lock,NULL);
	pthread_create(&tid,NULL,&even,NULL);
	pthread_create(&pid,NULL,&odd,NULL);
	if(rv)
	{
		printf("Error");
	}
	pthread_join(tid,NULL);
}

