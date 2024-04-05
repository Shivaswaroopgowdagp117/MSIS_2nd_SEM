#include <stdio.h>
#include <stdlib.h>

void transpose(int *mat, int row, int col);
int main()
{
    int i, j;
    int mat[3][4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mat[i][j] = rand() % 2 + 4 * i;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The transpose of a matrice is:\n");
    transpose((int *)mat, 3, 4);
    return 0;
}
void transpose(int *mat, int row, int col)
{
    int i, j;
    for (j = 0; j < col; j++)
    {
        for (i = 0; i < row; i++)
        {

            printf("%d\t", *(mat + (i * col) + j));
        }
        printf("\n");
    }
}