/*Implement a C function to find the transpose of a given
matrix. The program should take a matrix as input, compute
its transpose, and display the result.*/


#include <stdio.h>

#define ROWS 5
#define COLS 5

void interchangeRows(int matrix[ROWS][COLS], int rows, int cols, int row1, int row2) {
    int temp[COLS];

    for (int i = 0; i < COLS; i++) {
        temp[i] = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp[i];
    }
}

void populateMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void displayMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    int row1, row2;

    populateMatrix(matrix);
    printf("Original Matrix:\n");
    displayMatrix(matrix);

    printf("Enter row numbers to be interchanged: ");
    scanf("%d %d", &row1, &row2);

    interchangeRows(matrix, ROWS, COLS, row1, row2);
    printf("Modified Matrix:\n");
    displayMatrix(matrix);

    return 0;
}