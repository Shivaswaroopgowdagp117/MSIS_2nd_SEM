/*Write a simple C program to generate a random number
without initializing the seed for the random number
generator {Within a span of "one second", if you keep
running the program multiple times, you should see the same
random number output}*/


#include <stdio.h>
#include <stdlib.h>
int main()
{
    int random_number = rand();
    printf("Random number (without seeding):%d\n",random_number);
    return 0;
}