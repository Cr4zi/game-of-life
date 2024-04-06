#include "../include/painter.h"
#include "raylib.h"

void drawWorld(int** world, int rows, int columns, int size)
{
    int currX = 0;
    int currY = 0;
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            if(world[j][i] == 1)
                DrawRectangle(currX, currY, size, size, BLACK);
            currX += size;
        }
        currY += size;
        currX = 0;
    }
}

void drawSeperators(int width, int height, int size, int spaces)
{
    /* Draw Rows Seperators */
    for(int i = 0; i < width; i+= spaces) {
        DrawRectangle(i, 0, size, height, BLACK);
    }

    /* Draws Columns Seperators */
    for(int i = 0; i < height; i += spaces) {
        DrawRectangle(0, i, width, size, BLACK);
    }
}
