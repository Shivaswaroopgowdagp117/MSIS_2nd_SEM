/*Further modify the above to print the total number of
executing threads.*/

#include <stdio.h>
#include <omp.h>
int main() 
{
    // start of OpenMP parallel region
    #pragma omp parallel
    {
        printf("Total number of executing threads = %d \n", omp_get_num_threads());
    }

    return 0;
}