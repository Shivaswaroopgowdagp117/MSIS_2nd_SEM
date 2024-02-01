/*Write a simple C program to generate a random number
 between 0 and 9.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int main()
 {
    printf("Random Number b/w 0&9:%d\n", rand()%10);
    return 0;    
 }