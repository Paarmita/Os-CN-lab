#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int size;

void *average (void *a){
	int i,sum=0;
	int *b= (int *)a;
	for (int i=0;i<size;i++){
		sum+=b[i];
	}
	sum/=size;
	return (void *)sum;
}

void *max(void *a){
	int *b=(int *)a;
	int i,max=b[0];
	for (int i=1;i<size;i++){
		if(max<b[i])
		max=b[i];
	}
	return (void *)max;
}

void *min(void *a){
	int *b=(int *)a;
	int i,min=b[0];
	for (int i=1;i<size;i++){
		if(min>b[i])
		min=b[i];
	}
	return (void *)min;
}

void main(){
	int *a;
	int i,avg,maxi,mini;
	printf("Enter size\n");
	scanf("%d",&size);
	a=(int*)malloc(sizeof(int)*size);

	for(i=0;i<size;i++){
		printf("enter %d no:",i);
		scanf("%d",&a[i]);
	}

	pthread_t tid1, tid2,tid3;

	pthread_create(&tid1,NULL,average,a);
	pthread_create(&tid2,NULL,min,a);
	pthread_create(&tid3,NULL,max,a);
	
	pthread_join(tid1,&avg);
	pthread_join(tid2,&maxi);
	pthread_join(tid3,&mini); 

	printf("Average: %d\n",avg);
	printf("Min: %d\n",maxi);
	printf("Max: %d\n", mini);
}
