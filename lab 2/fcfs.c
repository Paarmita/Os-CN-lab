#include<stdio.h>
 
int main()
{
	int n,burstTime[20],WaitTime[20],TurnAroundTime[20],avWaitTime=0,avTurnAroundTime=0,i,j;
	printf("Enter total number of processes(maximum 20):");
	scanf("%d",&n);
 
	printf("\nEnter Process Burst Time\n");
	for(i=0;i<n;i++){
		printf("P[%d]:",i+1);
		scanf("%d",&burstTime[i]);
	}
 
	WaitTime[0]=0;    //Waiting time for first process is 0
 
	//calculating Waiting time
	for(i=1;i<n;i++){
		WaitTime[i]=0;
		for(j=0;j<i;j++)
			WaitTime[i]+=burstTime[j];
	}
 
	printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
	//calculating turnaround time
	for(i=0;i<n;i++){
		TurnAroundTime[i]=burstTime[i]+WaitTime[i];
		avWaitTime+=WaitTime[i];
		avTurnAroundTime+=TurnAroundTime[i];
		printf("\nP[%d]\t%d\t%d\t%d",i+1,burstTime[i],WaitTime[i],TurnAroundTime[i]);
	}
 
	avWaitTime/=i;
	avTurnAroundTime/=i;
	printf("\nAverage Waiting Time:%d",avWaitTime);
	printf("\nAverage Turnaround Time:%d\n",avTurnAroundTime);
 
	return 0;
}
