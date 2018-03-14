/*
The multi-level feedback queue job scheduling algorithm primarily includes multiple job queues in the system. 
It scans the job queue and separates the jobs into different categories based on their need for the processor.
The algorithm allocates the jobs or processes to different queues based on their CPU execution time. 
If a process has a large burst-time, then it is automatically moved to a lower-priority queue. 
This technique helps to prevent starvation of lower priority processes too.
The algorithm prefers shorter jobs with low burst times and it prefers input/output bound processes. 
A process known as aging promotes lower priority jobs to a higher priority queue at regular intervals of time.
An important thing to note is that there is a difference between multi-level feedback queue scheduling algorithm and 
multi-level queue scheduling algorithm.
In the multi level feedback queue scheduling algorithm, the processes are permanently assigned to a queue whereas, 
in a multilevel feedback scheduling algorithm, the processes can move between multiple queues according to their requirements.
The multilevel feedback queue scheduling algorithm makes use of both first come first serve algorithm and 
shortest job first algorithm.
*/

#include<stdio.h> 
 
#define N 10 
 
typedef struct 
{ 
	int process_id, arrival_time, burst_time, priority;
	int q, ready; 
}process_structure; 
 
int Queue(int t1) 
{ 
	if(t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
	{ 
		return 1; 
	} 
	else
	{
		return 2; 
	}
} 
 
int main() 
{ 
	int n, count, temp_process, time, j, y; 
	process_structure temp; 
	printf("Enter Total Number of Processes:\t"); 
	scanf("%d", &n);  
	process_structure process[n];			//process array storing process structure  
	for(count = 0; count < n; count++) 
	{ 
		printf("\nProcess ID:\t"); 
		scanf("%d", &process[count].process_id); 
		printf("Arrival Time:\t"); 
		scanf("%d", &process[count].arrival_time); 
		printf("Burst Time:\t"); 
		scanf("%d", &process[count].burst_time); 
		printf("Process Priority:\t"); 
		scanf("%d", &process[count].priority); 

		temp_process = process[count].priority; 		//storing the priority order in queue
		process[count].q = Queue(temp_process);
		process[count].ready = 0; 
	}
	time = process[0].burst_time; 

	for(y = 0; y < n; y++) 
	{ 
		for(count = y; count < n; count++) 
		{ 
			if(process[count].arrival_time < time) 
			{
				process[count].ready = 1; 		// checking if arrival time is less than time go to queue
			} 
		} 
		for(count = y; count < n - 1; count++) 			//implement rr 
		{
			for(j = count + 1; j < n; j++) 
			{ 
   				if(process[count].ready == 1 && process[j].ready == 1) 
				{ 
					if(process[count].q == 2 && process[j].q == 1) 
					{ 
						temp = process[count]; 
						process[count] = process[j]; 
						process[j] = temp; 
					} 
				} 
			} 
		} 
		for(count = y; count < n - 1; count++) 
		{ 
			for(j = count + 1; j < n; j++) 
			{
				if(process[count].ready == 1 && process[j].ready == 1) 
				{ 
					if(process[count].q == 1 && process[j].q == 1) 
					{ 
						if(process[count].burst_time > process[j].burst_time) 
						{ 
							temp = process[count]; 
							process[count] = process[j]; 
							process[j] = temp; 
						} 
						else 
						{ 
							break; 
						} 
					} 
				} 
			} 
		} 
		printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time); 
		time = time + process[y].burst_time; 
		for(count = y; count < n; count++) 
		{ 
			if(process[count].ready == 1) 
			{ 
				process[count].ready = 0; 
			} 
		} 
	} 
return 0; 
}
