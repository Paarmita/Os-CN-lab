#include <stdio.h>
#include <semaphore.h>
#include <stdbool.h>
#include <pthread.h>

int i = 0;
sem_t sem[5];

   
void left(void* j){
    int i = (int)j;
    while(true){ // put 'break' at appropriate location !!!
        
        printf("Philospher %d thinking\n",i);
        sem_wait(&sem[i]);
        printf("Philospher %d picks left fork\n",i);
        sem_wait(&sem[(i+1) % 5]);
        printf("Philospher %d picks right fork\n",i);
        printf("Philospher %d begin eating\n",i);
        sleep(1);
        printf("Philospher %d finish eating\n",i);
        sem_post(&sem[i]);
        printf("Philospher %d drops left fork\n",i);
        sem_post(&sem[(i+1) % 5]);
        printf("Philospher %d drops right fork\n",i);
    }

}


void right(void* j){
    int i = (int)j;
    while(true){ // put 'break' at appropriate location !!!
        printf("Philospher %d thinking\n",i);
        sem_wait(&sem[(i+1) % 5]);
        printf("Philospher %d picks right fork\n",i);
        sem_wait(&sem[i]);
        printf("Philospher %d picks left fork\n",i);
        printf("Philospher %d begin eating\n",i);
        sleep(1);
        printf("Philospher %d finish eating\n",i);
        sem_post(&sem[(i+1) % 5]);
        printf("Philospher %d drops right fork\n",i);
        sem_post(&sem[i]);
        printf("Philospher %d drops left fork\n",i);    
    }
}
   
int main(){ // initalise thread and semaphores.
    pthread_t tid[5];
    int k,a;
    for (a = 0; a<5;a++){
        sem_init(&sem[a],0,1);
    }
    for (k = 0; k< 4; k++){
        int rv = pthread_create(&tid[i], NULL, left, (void*)k);
        
    }
    int rv1 = pthread_create(&tid[i], NULL, right, (void*)k);
    
        pthread_exit(NULL);
    return 0;
}
