#include <raylib.h>
#include <stdlib.h>
#include <math.h>

#define GRID_HEIGHT 20
#define GRID_WIDTH 10


typedef struct {
	bool isFull;
	bool isStatic;
	Color color;
} Pixel;



//Draw

void DrawBoard(Pixel mat[GRID_WIDTH][GRID_HEIGHT], int pixelSize) {
	DrawRectangle(100, 0, GRID_WIDTH * pixelSize, GRID_HEIGHT * pixelSize, BLACK);
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			DrawRectangle(100 + i * pixelSize, j * pixelSize, pixelSize - 1, pixelSize - 1, mat[i][j].color);
		}
	}
}


//Init

void Init(Color backgroundColor) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1500, 900, "Window");
	ClearBackground(backgroundColor);
	SetTargetFPS(60);
}



//Main

int main() {
	//Init
	Color backgroundColor = (Color) {10, 10, 10, 255};
	Init(backgroundColor);
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	int pixelSize = screenHeight / GRID_HEIGHT;
	Pixel mat[GRID_WIDTH][GRID_HEIGHT];
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			mat[i][j].isFull = false;
			mat[i][j].isStatic = false;
			mat[i][j].color = (Color) {20, 20, 20, 255};
		}
	}
	mat[2][3].color = MAGENTA;
	mat[3][2].color = MAGENTA;
	mat[3][3].color = MAGENTA;
	mat[3][4].color = MAGENTA;

	while (!WindowShouldClose()) {
	//Resize
		if (IsWindowResized()) {
			screenWidth = GetScreenWidth();
			screenHeight = GetScreenHeight();
		}
	
	//Drawing
		BeginDrawing();
			ClearBackground(backgroundColor);
			DrawBoard(mat, pixelSize);
		EndDrawing();
	}
	CloseWindow();

	//De-init
	return 0;
}
