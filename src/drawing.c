#include "../include/drawing.h"

#include "raylib.h"

void draw(int** world, int cell_size)
{
    Vector2 mousePos = GetMousePosition();
    int posX = mousePos.x / cell_size;
    int poxY = mousePos.y / cell_size;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        world[posX][poxY] = 1;
    }


}
