#include<stdio.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

	int a=0,b=1,n=a+b,i;

	//printf("Enter the number of a Fibonacci Sequence:\n");
	int  val = atoi(argv[1]);
	//scanf("%d", &i);

	pid_t pid = fork(); //fork() returns 0 to the child

	if(pid<0){
        	printf("Error \n");
        	exit(-1);
	}

	if (pid == 0){
		//child process
    		printf("Child is make the Fibonacci\n");
    		printf("0 %d ",n);
    		while (val>0) {
        		n=a+b;
        		printf("%d ", n);
        		a=b;b=n;
        		val--;
        	if (val == 0){
			printf("\nChild ends\n");
			printf("parent id %d  \n", getppid());
			printf("child id %d  \n",getpid());
			
		}	
		}
	}
	else{
	printf("Parent is waiting for child to complete...\n");
	waitpid(pid, NULL, 0);			//returns the process ID of the terminated process 
	printf("process id %d  ",getpid());
	printf("Parent ends\n");
    }
    return 0;
}
