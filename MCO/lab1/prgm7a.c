#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i,j;
    int arr[5][10];
    for(i=0;i<5;i++){
        for(j=0;j<10;j++)
        {
            arr[i][j]=rand()%10;
            printf("\t");
        }
        printf("\n");
            
    }

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            printf("%d",arr[i][j]);
            printf("\t");

        }
        printf("\n");
 
   }
   return 0;
}
