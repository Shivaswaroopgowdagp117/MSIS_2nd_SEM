#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_matrice(int *mat, int row, int col);
void subtraction(int *mat_1, int *mat_2, int row, int col);
int generate_rand(int min,int max);


int main()
{
     clock_t start_time,end_time;
    double total_time;
    int row_1, row_2, col_1, col_2, i, j;
    printf("Enter the row and column of matrice 1:\n");
    scanf("%d%d", &row_1, &col_1);
    printf("Enter the row and column of matrice 2:\n");
    scanf("%d%d", &row_2, &col_2);
    printf("\n");
    int mat_1[row_1][col_1], mat_2[row_2][col_2];
    //The rows and column of matrice 1 and 2 must be same for subtracting
   
    
    if (row_1==row_2 && col_1==col_2)
    {
        start_time=clock();
        generate_matrice((int *)mat_1, row_1, col_1);
        generate_matrice((int *)mat_2, row_2, col_2);
        printf("After Subtraction:\n");
        subtraction((int*)mat_1,(int*)mat_2,row_1,col_1);
         end_time=clock();
        
    }

    else
    {
        printf("Subtraction is not possible \n");
    }
     total_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;
     printf("\nThe time required for subtracting two matrice is %fs.\n",total_time);
    return 0;
}
void generate_matrice(int *mat, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(mat + (i * col) + j) = generate_rand(20,50);
            printf("%d\t", *(mat + (i * col) + j));
        }
        printf("\n");
    }

    printf("\n");
}
int generate_rand(int min,int max)
{
    return min+rand()%(max-min+1);
}
void subtraction(int *mat_1, int *mat_2, int row, int col)
{
    int mat[row][col];
 for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
           mat[i][j]=*(mat_1+(i*col)+j) - *(mat_2+(i*col)+j);
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}