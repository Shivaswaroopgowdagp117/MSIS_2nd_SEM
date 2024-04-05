/*Modify your code so that you convert the code into a
function called sort(). Signature of matrix_sort() can be
as below:
 int sort(int mat[][], int rows, int cols).
Let the return value of sort() be zero always.
Write a suitable main() which invokes sort() and observe
your results.*/


#include <stdio.h>

#define ROWS 5
#define COLS 5

int sort(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
    return 0;
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

    populateMatrix(matrix);
    printf("Original Matrix:\n");
    displayMatrix(matrix);

    sort(matrix, ROWS, COLS);
    printf("Sorted Matrix:\n");
    displayMatrix(matrix);

    return 0;
}