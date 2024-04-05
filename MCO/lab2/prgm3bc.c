#include <stdio.h>

void interchange_rows(int mat[][100], int rows, int cols, int row1, int row2) {
    // Ensure row numbers are within bounds
    if (row1 <= 0 || row1 > rows || row2 <= 0 || row2 > rows) {
        printf("Invalid row numbers!\n");
        return;
    }

    // Interchange rows
    for (int j = 0; j < cols; j++) {
        int temp = mat[row1 - 1][j];
        mat[row1 - 1][j] = mat[row2 - 1][j];
        mat[row2 - 1][j] = temp;
    }
}

int main() {
    int rows, cols, row1, row2;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Enter the two row numbers to interchange (1-based): ");
    scanf("%d %d", &row1, &row2);

    interchange_rows(mat, rows, cols, row1, row2);

    printf("Matrix after interchanging rows:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}