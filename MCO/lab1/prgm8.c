/*Write a C program to populate a matrix of size 20*50 by
generating random numbers in the range 101 to 201. Display
the matrix to the screen. Also determine the smallest,
largest, as well as the sum of all the elements of the
matrix and display the results to the screen. Find the
total time taken for the execution of your computations and
output the value*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ROWS 20
#define COLS 50

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

void populateMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 101 + 101;
        }
    }
}

int minValue(int matrix[ROWS][COLS]) {
    int min = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int maxValue(int matrix[ROWS][COLS]) {
    int max = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int sumValues(int matrix[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
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
    double start, end;

    start = getTime();

    populateMatrix(matrix);
    printf("Smallest: %d\n", minValue(matrix));
    printf("Largest: %d\n", maxValue(matrix));
    printf("Sum: %d\n", sumValues(matrix));
    displayMatrix(matrix);

    end = getTime();

    printf("Time taken: %f seconds\n", end - start);

    return 0;
}