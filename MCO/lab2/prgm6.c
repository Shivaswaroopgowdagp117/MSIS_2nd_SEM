/*Develop a C program to subtract one matrix from another.
Make sure they are compatible by comparing their rows and
columns; give an error message otherwise. The program
should populate both the matrices with random numbers
between 20 and 50, display the matrices first and later
display the result matrix.
How much time does your computation take?
Convert the code to a function and determine how much time
the code takes when your function is invoked by your main.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ROWS 5
#define COLS 5

void subtractMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void populateMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 31 + 20; // Random numbers between 20 and 50
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

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main() {
    int mat1[ROWS][COLS];
    int mat2[ROWS][COLS];
    int result[ROWS][COLS];
    double start, end;

    srand(time(0)); // Seed for random number generation

    populateMatrix(mat1);
    printf("Matrix 1:\n");
    displayMatrix(mat1);

    populateMatrix(mat2);
    printf("Matrix 2:\n");
    displayMatrix(mat2);

    start = getTime();

    subtractMatrices(mat1, mat2, result);
    printf("Result Matrix:\n");
    displayMatrix(result);

    end = getTime();

    printf("Time taken: %f seconds\n", end - start);

    return 0;
}