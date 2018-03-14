#include<stdio.h>
#include <sys/types.h>
 
int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sumOdd = 0, sumEven = 0, n, i;
    n = fork();
 
    // Checking if n is not 0
    if (n > 0) {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 == 0)
                sumEven = sumEven + a[i];
        }
        printf("Parent process");
        printf("Sum of even no: %d  \n", sumEven);
    }
 
    // If n is 0 i.e. we are in child process
    else {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 != 0)
                sumOdd = sumOdd + a[i];
        }
        printf("Child process");
        printf("Sum of odd no: %d  \n", sumOdd);
    }
    return 0;
}
