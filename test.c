#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

#define MATRIX_SIZE 5

int matrixA[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
};

int matrixB[MATRIX_SIZE][MATRIX_SIZE] = {
        {2, 0, 1, 4, 5},
        {1, 3, 5, 7, 9},
        {6, 4, 8, 2, 10},
        {11, 13, 15, 17, 19},
        {20, 22, 24, 26, 28}
};

int resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

// Function to be executed by each thread
void *multiplyRow(void *arg) {
    int row = *((int *)arg);

    for (int col = 0; col < MATRIX_SIZE; col++) {
        resultMatrix[row][col] = 0;
        for (int k = 0; k < MATRIX_SIZE; k++) {
            resultMatrix[row][col] += matrixA[row][k] * matrixB[k][col];
        }
    }

    exit();
}

int main() {
    int tid[MATRIX_SIZE];

    // Create threads
    for (int i = 0; i < MATRIX_SIZE; i++) {
        tid = thread_create(multiplyRow, &i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MATRIX_SIZE; i++) {
        thread_join(tid[i]);
    }

    // Print the result matrix
    printf("Result Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
