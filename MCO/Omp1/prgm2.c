/*2. Modify the above to print the thread id of the executing
thread, with each disply message.*/

#include <stdio.h>
#include <omp.h>
int main() 
{
    // start of OpenMP parallel region
    #pragma omp parallel
    {
        printf("Hello from thread = %d \n", omp_get_thread_num());
    }
    // OpenMP parallel region ends here

    printf("\nI'm the master thread!\n");
    return 0;
}