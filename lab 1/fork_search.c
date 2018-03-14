#include<stdio.h>
#include <sys/types.h>
 
int main()
{
    int key = 10;
    int id = fork();
 
    // Checking value of process id returned by fork
    if (id > 0)  {
        printf("Parent process \n");
        int a[] = { 3, 8, 4, 10, 80 };
        int n = 5, flag, i;

        for (i = 0; i < n; i++)
        {

            if (a[i] != key) {
                flag = 0;
            }
            else{
                flag = 1;
            }
        }
        if (flag == 1) {
            printf("key is not present in array");
        }
        else {
            printf("key is present in array \n");
        }
    }
 
    // If n is 0 i.e. we are in child process
    else {
        printf("Child process \n");
        printf("numbers to be search is %d", key);
    }
 
    return 0;
}

