#include<stdio.h>
#include<stdlib.h>


int need[5][3];
int allo[5][3] = {  {0,1,0},{2,0,0},
                    {3,0,2},{2,1,1},
                    {0,0,2}
                 };
int max[5][3] = {   {7,5,3},{3,2,2},
                    {9,0,2},{2,2,2},
                    {4,3,2}
                 };

int available[3] = {3,3,2}; 
int process[5], safe[5];

void main()
{   
    int i=0,j=0,count=0;
    char finish[]={0,0,0,0,0};
    //printf("Enter the availibility of 3 resource :");
   
    // for(j=0;j<3;j++)
    //     scanf("%d",&available[j]);
    // printf("Available instances:");
    // for(j=0;j<3;j++)
    //     printf("%d ",available[j]);
   
    // printf("\n");
    // printf("Enter Allocation matrix: ");
    // for(i=0;i<5;i++)
    // {    for(j=0;j<3;j++)
    //     scanf("%d",&allo[i][j]);

    // }
    // printf("\n");
    // printf("Enter Max matrix: ");
    for(i=0;i<5;i++)
    {    for(j=0;j<3;j++)
            need[i][j]=max[i][j]-allo[i][j];
    }

    //printing allocation matrix
    printf("Allocation\tmax\t\tneed    \n");
    for(i=0;i<5;i++)
    {    for(j=0;j<3;j++)
        {    printf("%d ",allo[i][j]);
        }
        printf("\t\t");
        for(j=0;j<3;j++)
        {   
            printf("%d ",max[i][j]);
        }printf("\t\t");
        for(j=0;j<3;j++)
        {   
            printf("%d ",need[i][j]);
        }printf("\t\t");
        printf("\n");           
    }

    int k=0;
    do{
        for(i=0;i<5;i++)
        {    if(finish[i]==0)
             {
                count=0;
                for(j=0;j<3;j++)
                {
                    if(need[i][j]<=available[j])
                    count++;
                   // printf("count = %d\n",count );
                }
               
                if(count==3)
                { 
                   for(j=0;j<3;j++)
                    {   
                        available[j]=available[j]-need[i][j];
                        allo[i][j]=allo[i][j]+need[i][j];
                        need[i][j]=0;   
                        available[j]=available[j]+allo[i][j];   
                    }
                    
                    process[k]=i;
                    finish[i]=1;
                    k++;
                }
            }
        }
        }while(finish[0]==0 || finish[1]==0 || 
        finish[2]==0 || finish[3]==0 ||
         finish[4]==0);
    
    if(finish[0]==1 && finish[1]==1 && 
        finish[2]==1 && finish[3]==1 && finish[4]==1)
        {
            printf("the safe sequence is: ");
            for(i=0;i<5;i++)
            {   
                printf("%d ",process[i]);   
            }
        }
    else
            printf("UNSAFE");
           

//main
}