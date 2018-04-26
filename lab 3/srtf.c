#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int arrival_time[] = {0,2,4,5};
int burst_time[] = 	 {5,3,1,4};
int service_time[] = {7,4,1,4};
//int service_time[] = {8,4,9,5};
int completion_time[] = {-1,-1,-1,-1};
int process_order[] = {-1,-1,-1,-1};
int arr_check[] = {-1,-1,-1,-1};

void main(){
	int i,j=0,count=0;
	int time=0,current_running=0;
	int flag =0;

	while(1)
	
	{
	
        for(i = 0; i < 4; i++)		//find the process with shortest remining time.
        {
              
        	if(flag == 0)
        	{
				if(arrival_time[i] <= time && service_time[i] > 0 )
					current_running = i;
        	}

        	else 
        	{
              	if(arrival_time[i] <= time && arr_check[current_running] == -1 && 
              		service_time[i] < service_time[current_running] && service_time[i] > 0)

              		current_running = i;
          	}

        	flag = 1;
        	//printf("arrival time =%d  current_running=%d service time=%d i=%d \n",arrival_time[i],current_running,service_time[i],i);
        }
        time++;
       
        if(arr_check[current_running] == -1)
        {
	        if(service_time[current_running] > 0)	
	    	service_time[current_running]--;

	        if(service_time[current_running] == 0)
	        {
	        	count++;
	        	completion_time[current_running] = time;
	        	process_order[j] = current_running;
	        	j++;
	        	arr_check[current_running] = 1;
	        	flag = 0;
	 			//printf("Process P%d. Completion Time= %d,\n",current_running,completion_time[current_running]);
	        }
		 }

		 else
		 {
		 	current_running++;
		 	time --;
		 }
        
        //count ++;
        // printf("time = %d\n",time);
		
		if(count == 4)
			break;

		//printf("arrival time =%d  current_running=%d service time=%d i=%d \n",arrival_time[i],current_running,service_time[i],i);
	}

	printf("Process Completion Order\n");
	for(i=0;i<4;i++)
	{
		printf(" P%d -> ",process_order[i]);
	}

	for(i=0;i<4;i++)
	{
		printf(" \ncompletion_time %d",completion_time[process_order[i]]);
	}

}
