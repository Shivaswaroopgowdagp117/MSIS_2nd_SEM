#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 20
#define column 50

int arr[row][column];

int generate_rand(int min,int max)
{
    return min+rand()%(max-min+1);
}
void data_to_mat()
{
    int i,j;
    int value;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            
                arr[i][j]=generate_rand(101,201);
            printf("\t");
        }
        printf("\n");
    }
}
void display()
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%d",arr[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}
void small_larg()
{
    int small=arr[0][0],large=0;
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(small>arr[i][j]){
                small=arr[i][j];
           // printf("Row is %d Column is %d\n",i,j);
            }
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(large<arr[i][j]){
                large=arr[i][j];
                      //  printf("Row is %d Column is %d\n",i,j);

            }
        }
    }
    printf("The smallest value in the matrice is %d and largest is %d\n",small,large);
    
}
void sum()
{
    int sum=0;
    int i,j;
      for(i=0;i<row;i++){
        for(j=0;j<column;j++){
           sum=sum+arr[i][j];
        }
    }
    printf("The sum of all the elements in the matrice is %d\n",sum);
}
int main()
{
    clock_t start,end;
    double total_time;
    start=clock();
    data_to_mat();
    display();
    small_larg();
    sum();
    end=clock();
    total_time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Total time taken for the exexution is %f",total_time);

    return 0;