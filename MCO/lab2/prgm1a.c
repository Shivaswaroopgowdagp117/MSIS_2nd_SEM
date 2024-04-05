/*Write a C program to search for a given element in a
matrix. The program should take a matrix and a target
element as input, and it should output whether the element
is present in the matrix or not*/


#include <stdio.h>

#define ROWS 5
#define COLS 5

int searchElement(int matrix[ROWS][COLS], int target) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == target) {
                return 1;
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
    int target;

    populateMatrix(matrix);
    printf("Matrix:\n");
    displayMatrix(matrix);

    printf("Enter target element: ");
    scanf("%d", &target);

    if (searchElement(matrix, target)) {
        printf("Element found!\n");
    } else {
        printf("Element not found!\n");
    }

    return 0;
}