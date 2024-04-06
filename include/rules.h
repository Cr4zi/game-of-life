#ifndef RULES_H
#define RULES_H
#include "raylib.h"

int countNeighbours(int** world, int x, int y);

void changeState(int** world, int x, int y);

void newGeneration(int** world, int rows, int columns);

#endif
