#include "raylib.h"

#include "../include/util.h"
#include "../include/painter.h"

#define WIDTH 1920
#define HEIGHT 1080
#define FPS 60

#define CELLS_RES_RATIO 10

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

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);
		drawSeperators(WIDTH, HEIGHT, 1);
		drawWorld(world, rows, columns, CELLS_RES_RATIO);

		EndDrawing();
	}

	free2DArray(world, rows);

	CloseWindow();

	return 0;
}
