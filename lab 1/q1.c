#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>

void * prime(void* k){

	int n,i,j,flag=0;
	n= (int)k;

	for(j=2;j<=n;j++){
	flag = 0;
		for(i=2;i<=j/2;i++){
		if(j%i == 0){
			flag=1;
			break;
		}	
		}

	if(flag ==0)
	printf("%d  ",j);
	}
}

int main(int argc, char *argv[]){
	
	pthread_t tid;						
	int n = atoi(argv[1]);
	int rv;
	rv = pthread_create(&tid,NULL,prime,(void*)n);

	if(rv){
	printf("ERROR");
	exit(1);
	}

	pthread_exit(NULL);
}
