/*Modify your code so that you convert the code into a
function called search().
Signature of search() can be as below:
int search(int mat[][], int rows, int cols, int
key).
Let the search function return 0 on finding the key,
and return -1 if the key is not present in the
matrix. Write a suitable main function which invokes
search() and observe your results.*/


#include <stdio.h>
#include <stdlib.h>

int search(int mat[][5], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return 0; // Key found
            }
        }
    }
    return -1; // Key not found
}

void populateMatrix(int matrix[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void displayMatrix(int matrix[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int matrix[5][5];
    int key;

    populateMatrix(matrix, rows, cols);
    printf("Matrix:\n");
    displayMatrix(matrix, rows, cols);

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (search(matrix, rows, cols, key) == 0) {
        printf("Key found in the matrix!\n");
    } else {
        printf("Key not found in the matrix!\n");
    }

    return 0;
}