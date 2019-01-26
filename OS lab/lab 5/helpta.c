#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t lock;
sem_t student;
sem_t ta;
int waiting =0;
int numChairs = 3;
int numTa =1;
int numStudent =10;
int totalStudent =0;


void checkChairs(int sid)
{

	sem_wait(&lock);
	if(waiting <= numChairs && waiting >=0)
	{

		waiting++;
		sem_post(&student);
		printf("Now student %d is waiting here.\n", sid);
		sem_post(&lock);
		
		sem_wait(&ta);
		totalStudent++;
	}
	
	else
	{
		printf("Student %d has gone home.\n", sid);
		totalStudent++;
		sem_post(&lock);
	}
}


void *studentHall(void *id)
{
	int sid = (int)id;
	checkChairs(sid);
	printf("Chairs Checked.\n");
}


void *taOffice(void* id)
{
	
	int sid = (int) id;
	while(1)
	{
		sem_wait(&student);
		sem_wait(&lock);
		waiting--;
		printf("TA is solving doubts of student %d.\n", sid);
			
		printf("\n");
		printf("Current scenario : \t Waiting Status = %d | \t Student Status = %d| \n", waiting, numStudent);
		printf("\n");
		sem_post(&ta);
		sem_post(&lock);
		if(totalStudent==10)
		break;
	}
}



int main ()
{
	sem_init(&lock, 0 , 1);
	sem_init(&student, 0 , numStudent);
	sem_init(&ta, 0, numTa);


	pthread_t studentid[10];
	pthread_t ta;

	int rv1;

	for(int i=0; i<10; i++)
	{ 
		rv1 = pthread_create(&studentid[i+1], NULL, studentHall, (void *) i+1);
	}

	int rv = pthread_create(&ta, NULL, taOffice, NULL);
	



	for(int i=0; i<10; i++)
	{ 
		pthread_join (studentid[i+1], NULL);
	}
	
	pthread_join(ta, NULL);


	

}
