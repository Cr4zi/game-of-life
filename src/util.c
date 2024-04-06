#include "../include/util.h"

#include <stdio.h>
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
    int random_val = 0;
    /* Get current times with nanosecond */
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    /* Seed the random number with nanoseconds */
    srand((unsigned int)ts.tv_nsec);

    /* Change the array values */
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            random_val = rand() % 10;

            /* Just for 0 to appear more */
            if(random_val < 8)
                random_val = 0;
            else
                random_val = 1;


            arr[i][j] = random_val;
        }
    }
}
