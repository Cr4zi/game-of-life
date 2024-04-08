#include "../include/drawing.h"

#include "raylib.h"

Vector2 draw(int** world, int cell_size)
{
    Vector2 mousePos = GetMousePosition();
    int posX = mousePos.x / cell_size;
    int poxY = mousePos.y / cell_size;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 ret_val = {posX, poxY};
        world[posX][poxY] = 1;
        return ret_val;
    }

    return (Vector2){0, 0};

}
