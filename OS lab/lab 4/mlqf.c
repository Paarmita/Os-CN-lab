#include<stdio.h>

int bt[]={64,12,7,2,41};
int st[]={64,12,7,2,41};
int order[5];
/*int q4[5], int q8[5], int q16[5];*/
//int Q[5];
int flag=1, qt, count=0,index=0;
//int n=5;
int main()
{
	while(1)
	{
		if(flag==1)
		{
			qt=4;
		}
		else if(flag==2)
		{
			qt=8;
		}	
		else if(flag==3)
		{
			qt=16;
		}

		for(int i=0;i<5;i++)
		{
			if(st[i]>0)
			{
				st[i]-=qt;
				if(st[i]<=0)
				{
					count++;
					order[index++]=i+1;
				}
			}
		}
		if(count==5)
		{
			break;
		}
		if(flag<3)
		{
			flag+=1;
		}
	}		
	printf("Order of processes\n");
	for(int i=0;i<5;i++)
	{
		printf("%d\n",order[i]);
	}
	return 0;
}
