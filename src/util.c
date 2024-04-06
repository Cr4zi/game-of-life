#include "../include/util.h"

#include <bits/time.h>
#include <stdlib.h>
#include <time.h>

int** make2DArray(int rows, int columns)
{
    int** arr = (int **)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(columns * sizeof(int));
    }

    return arr;

}

void free2DArray(int** arr, int rows)
{
    for(int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void setRandomValues(int** arr, int rows, int columns)
{
    // Get current times with nanosecond
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    // Seed the random number with nanoseconds
    srand((unsigned int)ts.tv_nsec);

    // Change the array values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}
