#include <stdio.h>

int main(){

    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];
    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    // Sort each row of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = j + 1; k < cols; k++) {
                if (mat[i][j] > mat[i][k]) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[i][k];
                    mat[i][k] = temp;
                }
            }
        }
    }

    printf("Sorted matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}