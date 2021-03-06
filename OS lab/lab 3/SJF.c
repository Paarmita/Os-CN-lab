/*In shortest job first scheduling algorithm, 
the processor selects the waiting process with the 
smallest execution time to execute next.
Arrival Time:       Time at which the process arrives in the ready queue.
Completion Time:    Time at which process completes its execution.
Burst Time:         Time required by a process for CPU execution.
Turn Around Time:   Time Difference between completion time and arrival time.          
					Turn Around Time = Completion Time - Arrival Time
Waiting Time(W.T): Time Difference between turn around time and burst time.
					Waiting Time = Turn Around Time - Burst Time*/
#include<stdio.h>
 
void main()
{
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter number of process:");
	scanf("%d",&n);
 
	printf("\nEnter Burst Time:\n");
	for(i=0;i<n;i++)
	{
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;			//contains process number
	}
 
	//sorting burst time in ascending order using selection sort
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			pos=j;
		}
 
	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;
 
	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
	}
 
	wt[0]=0;				//waiting time for first process will be zero
 
	//calculate waiting time
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		wt[i]+=bt[j];			//adding burst time to waiting time
 
	total+=wt[i];
	}
	 
	avg_wt=(float)total/n;			//average waiting time
	total=0;
 
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];		//calculate turnaround time = burst time + waiting time
		total+=tat[i];
		printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
 
	avg_tat=(float)total/n;     //average turnaround time
	printf("\n\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
