/*Implement a C program to multiply two integer matrices.
The program should take two matrices as input from the user
and display the result. If the two matrices are not
compatible for multiplication, output an adequate message
to the user.*/


#include <stdio.h>

#define ROWS1 5
#define COLS1 5
#define ROWS2 5
#define COLS2 5

void multiplyMatrices(int mat1[ROWS1][COLS1], int mat2[ROWS2][COLS2], int result[ROWS1][COLS2]) {
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void populateMatrix(int matrix[ROWS1][COLS1]) {
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void displayMatrix(int matrix[ROWS1][COLS1]) {
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[ROWS1][COLS1];
    int mat2[ROWS2][COLS2];
    int result[ROWS1][COLS2];

    populateMatrix(mat1);
    printf("Matrix 1:\n");
    displayMatrix(mat1);

    populateMatrix(mat2);
    printf("Matrix 2:\n");
    displayMatrix(mat2);

    if (COLS1 != ROWS2) {
        printf("Error: The matrices are not compatible for multiplication\n");
        return 1;
    }

    multiplyMatrices(mat1, mat2, result);
    printf("Result:\n");
    displayMatrix(result);

    return 0;
}