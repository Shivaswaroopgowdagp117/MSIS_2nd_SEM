// Write a C program to display the current time


#include <stdio.h>
#include <time.h>
int main()
{
    time_t now = time(NULL);
    printf("Current Time :%s\n",ctime(&now));
    return 0;
}