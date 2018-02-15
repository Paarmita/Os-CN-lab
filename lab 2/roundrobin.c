#include <stdio.h>
#include<stdlib.h>

int btime[5] = {2,6,1,3,8};
int tQ = 2;		//quantum time

int main(){
	int count=5;
	int i;
	int tR[5];
	for(i=0;i<count;i++){
		tR[i] = btime[i];			//copy of burst time in tR
	}
	int bMax;
	for(i=0;i<count;i++){
		if(bMax<btime[i])
			bMax = btime[i];		//max burst time
	}
	int turnAroundTime=0;
	int TotalturnAroundTime=0;
	int TotalWaitingTime=0;

	int rem = bMax/tQ;

	//Sequence of Processes

	while(((bMax/tQ)+rem)>0){				//
		bMax-=tQ;					//tracking the time remaining		
		for(i=0;i<count;i++){				//traverse all processes
			if(tR[i]>0){				//if burst time>0
			printf("Executing P[%d]\n",i+1);
			tR[i]-=tQ;				//decrease burst time by quantum
			if(tR[i]<=0){
				turnAroundTime+=tR[i]+tQ;		//increase turn around time value by quantum and burst time
				printf("Process P[%d] Completed!\n",i+1);

				printf("\tTurn Around Time for Process P[%d] : %d\n",i+1,turnAroundTime);
				TotalturnAroundTime+=turnAroundTime;
                       
				printf("\t\tWaiting Time for Process P[%d] : %d\n",i+1,turnAroundTime-btime[i]);
				TotalWaitingTime+=(turnAroundTime-btime[i]);		//total wait time = turn around time - burst time
          
			}
			if(tR[i]>0)
			turnAroundTime += tQ;
			}
		}      
	}
   
	printf("Average Turn Around Time for Processes : %f\n",(TotalturnAroundTime*1.0)/count);                      
	printf("Average Waiting Time for Processes : %f\n",(TotalWaitingTime*1.0)/count);

	return 0;
}
