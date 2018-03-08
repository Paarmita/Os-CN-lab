#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;
int n=0;

void* even()
{
	//if n is even lock otherwise unlock
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
	//if n is odd lock otherwise unlock
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
	int t = pthread_mutex_init(&lock,NULL);
	pthread_create(&tid,NULL,&even,NULL);
	pthread_create(&pid,NULL,&odd,NULL);
	if(t)
	{
		printf("Error");
	}
	pthread_join(tid,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}

