/*Write a simple C program to generate a random number
 between 0 and 9.*/


 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int main()
 {
    srand(time(NULL));
    int a = rand()%9+1;
    printf("Random Number b/w 0&9:%d\n", a!=0);
    return 0;    
 }