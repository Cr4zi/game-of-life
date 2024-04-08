#include "../include/rules.h"
#include <stdio.h>

int countNeighbours(int** world, int x, int y)
{
    int sum = 0;

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            sum += world[x+i][y+j];
        }
    }

    sum -= world[x][y];

    return sum;
}

void changeState(int** world, int** next, int x, int y)
{
    int currState = world[x][y];

    int neighbours = countNeighbours(world, x, y);

    /* No need to implement second rule */

    /* First and third rule if live cell with fewer than two live neibours or more than 3 live neighbours die */
    if(currState == 1 && (neighbours < 2 || neighbours > 3))
        next[x][y] = 0;
    /* Fourth rule any dead cell with exactly 3 live neighbours becomes a live cell */
    else if(currState == 0 && neighbours == 3)
        next[x][y] = 1;
    else if (currState == 1 && (neighbours == 2 || neighbours == 3))
        next[x][y] = 1;
}


void newGeneration(int** world, int** next, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(i == 0 || i == rows - 1 || j == 0 || j == -1)
                next[i][j] = 0;
            else
                changeState(world, next, i, j);
        }
    }

}
