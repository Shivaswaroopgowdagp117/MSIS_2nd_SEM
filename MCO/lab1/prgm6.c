/*Write a C program to find the execution time of
outputting Hello world 10 times and 10,000 times
respectively.*/


#include <stdio.h>
#include <time.h>

void print(int);

int main()
{
    clock_t start_time,end_time;
    double total_time;
    start_time=clock();
    print(10000);
    end_time=clock();
    total_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("The time required for printing hello world 10000 times is %f",total_time);
    printf("\n");
    start_time=clock();
    print(10);
    end_time=clock();
    total_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("The time required for printing hello world 10 times is %f",total_time);


    return 0;
}
void print(int num)
{
    for(int i=0;i<num;i++)
        printf("Hello World\n");
}
