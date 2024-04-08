#include "raylib.h"

#include <stdio.h>

#include "../include/util.h"
#include "../include/painter.h"
#include "../include/rules.h"
#include "../include/drawing.h"

#define WIDTH 1920
#define HEIGHT 1080
#define FPS 15

#define CELLS_RES_RATIO 20

int main()
{

	/* Initialize window */
	InitWindow(WIDTH, HEIGHT, "Conway's Game of Life");

	/* FPS */
	SetTargetFPS(FPS);

	int rows = WIDTH / CELLS_RES_RATIO;
	int columns = HEIGHT / CELLS_RES_RATIO;

	int** world = make2DArray(rows, columns);
	setRandomValues(world, rows, columns);

	int** next = make2DArray(rows, columns);
	copyArrToArr(world, next, rows, columns);

	int should_draw = 0;

	while(!WindowShouldClose()) {
		BeginDrawing();

		if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			if (should_draw) should_draw = 0;
			else should_draw = 1;
		}

		if (!should_draw) {
			// copyArrToArr(world, next, rows, columns);
			newGeneration(world, next, rows, columns);
			copyArrToArr(next, world, rows, columns);

		} else {
			draw(world, CELLS_RES_RATIO);
			copyArrToArr(world, next, rows, columns);
		}

		ClearBackground(RAYWHITE);
		drawSeperators(WIDTH, HEIGHT, 1, CELLS_RES_RATIO);
		drawWorld(world, rows, columns, CELLS_RES_RATIO);


		EndDrawing();
	}

	free2DArray(next, rows);
	free2DArray(world, rows);

	CloseWindow();

	return 0;
}
