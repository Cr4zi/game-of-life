#ifndef UTIL_H

#define UTIL_H

#include "raylib.h"

int** make2DArray(int rows, int columns);

void free2DArray(int** arr, int rows);

void setRandomValues(int** arr, int rows, int columns);

#endif
