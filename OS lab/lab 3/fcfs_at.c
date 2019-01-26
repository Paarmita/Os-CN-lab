#include <stdio.h>  

 int wt[10],bt[10],at[10],tat[10],n;  
 float awt,atat;  
 void input(){  
        printf("Enter Number of processes:");  
        scanf("%d",&n);  
        int i;  
        for(i=0;i<n;i++)  
        {  
          printf("Enter Burst Time of process %d:",i+1);  
          scanf("%d",&bt[i]);         
          printf("Enter Arrival Time of process %d:",i+1);  
          scanf("%d",&at[i]);         
        }  
 }  
 void calculate(){  
    wt[0]=0;  
    atat=tat[0]=bt[0];  
    int btt=bt[0];              //to store total burst time sum  
    int i;  

    for(i=1;i<n;i++){  
      wt[i]=btt-at[i];  //wait time =  total burst time - arrival time
      btt+=bt[i];        // total burst time = add aburst times
      awt+=wt[i];       // avg wait time
      tat[i]= wt[i]+bt[i];   //turn around time = wait time + burst time
      atat+=tat[i];    
    }  
    atat/=n;  
    awt/=n;       
 }  
 void display(){  
    int i;  
    printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n");  
    for(i=0;i<n;i++)  
    {  
    printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]);          
    }    
    printf("Average Waiting Time: %f\nAverage Turn Around Time: %f \n",awt,atat);  
 }    
 int main(){  
       input();  
       calculate();  
       display();   
  
 }  