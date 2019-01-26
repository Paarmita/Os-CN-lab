/*example of a threaded application. It creates two numbers, x and y, and creates a second thread. 
The first thread increments y until it has the value of 100,
while the second thread increments x until it has the value of 100 at the same time. 
When this is done, it joins the second thread back with the main program and prints the results. 
Note how, even though x was changed by the second thread, it has been changed for the main program too!*/

#include <pthread.h>
#include <stdio.h>

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{
	/* increment x to 100 */
	int *x_ptr = (int *)x_void_ptr;
	while(++(*x_ptr) < 100);

	printf("x increment finished\n");
	
	printf("x: %d \n",*x_ptr);

	/* the function must return something - NULL will do */
	return NULL;
}

int main()
{
	int x = 0, y = 0;
	/* show the initial values of x and y */
	printf("x: %d, y: %d\n", x, y);
	/* this variable is our reference to the second thread */
	pthread_t tid;
	/* create a second thread which executes inc_x(&x) */
	if(pthread_create(&tid, NULL, inc_x, &x)) 
	{
		printf("Error creating thread\n");
		return 1;
	}
	/* increment y to 100 in the first thread */
	while(++y < 100);

	printf("y increment finished\n");
	printf("y: %d \n",y);
	printf("x: %d \n",x);

	/* wait for the second thread to finish */
	if(pthread_join(tid, NULL)) 
	{
		printf("Error joining thread\n");
		return 2;
	}
/* show the results - x is now 100 thanks to the second thread */
printf("x: %d, y: %d\n", x, y);

return 0;
}
