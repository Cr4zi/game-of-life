#ifndef UTIL_H

#define UTIL_H

#include "raylib.h"

int** make2DArray(int rows, int columns);

void free2DArray(int** arr, int rows);

/* Setting random values between 0 - 1 in arr */
void setRandomValues(int** arr, int rows, int columns);

/* Copying arr1 values into arr2 */
void copyArrToArr(int** arr1, int** arr2, int rows, int columns);

/* Swaping arr1 and arr2 values */
void swapTwoArrays(int** arr1, int** arr2, int rows, int columns);

#endif
