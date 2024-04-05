#include <stdio.h>
#include <stdlib.h>

void generate_matrice(int *mat, int row, int col);
void multiplication(int *mat_1, int *mat_2, int row_1, int col_1, int row_2, int col_2);

int main()
{
    int row_1, row_2, col_1, col_2, i, j;
    printf("Enter the rows of matrice 1 and 2:\n");
    scanf("%d%d", &row_1, &row_2);
    printf("Enter the column size of matrice 1 and 2:\n");
    scanf("%d%d", &col_1, &col_2);
    printf("\n");
    int mat_1[row_1][col_1], mat_2[row_2][col_2];
    //  The number of columns of the first matrix in the
    //  multiplication process must equal the number of rows of the second matrix.
    if (col_1 == row_2)
    {
        generate_matrice((int *)mat_1, row_1, col_1);
        generate_matrice((int *)mat_2, row_2, col_2);
        printf("After multiplication:\n");
        multiplication((int *)mat_1, (int *)mat_2, row_1, col_1, row_2, col_2);
    }
    else
    {
        printf("Multiplication is not possible \n");
    }

    return 0;
}
void generate_matrice(int *mat, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(mat + (i * col) + j) = i * j + rand() % 4;
            printf("%d\t", *(mat + (i * col) + j));
        }
        printf("\n");
    }

    printf("\n");
}
void multiplication(int *mat_1, int *mat_2, int row_1, int col_1, int row_2, int col_2)
{
    // the new matrice will have same rows as matice 1 and column as matrice 2
    int mat[row_1][col_2];
    for (int i = 0; i < row_1; i++)
    {
        for (int j = 0; j < col_2; j++)
        {
            mat[i][j] = 0;
            for (int k = 0; k < col_1; k++)
                mat[i][j] += (*(mat_1 + (i * col_1) + k)) * (*(mat_2 + (k * col_2) + j));
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}