#include "raylib.h"

#include <stdio.h>

#include "../include/util.h"
#include "../include/painter.h"
#include "../include/rules.h"

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

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);
		drawSeperators(WIDTH, HEIGHT, 1);
		drawWorld(world, rows, columns, CELLS_RES_RATIO);

		newGeneration(next, rows, columns);
		swapTwoArrays(world, next, rows, columns);
		copyArrToArr(world, next, rows, columns);

		EndDrawing();
	}

	free2DArray(next, rows);
	free2DArray(world, rows);

	CloseWindow();

	return 0;
}
