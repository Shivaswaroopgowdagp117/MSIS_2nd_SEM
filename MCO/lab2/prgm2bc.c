#include <stdio.h>

// Function to sort the elements of a matrix in ascending order
int sort(int mat[][100], int rows, int cols) {
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
    return 0;
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: \n ");
    scanf("%d %d", &rows, &cols);

    int mat[100][100];
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    sort(mat, rows, cols);

    printf("Sorted matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}