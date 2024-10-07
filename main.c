#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRID_HEIGHT 20
#define GRID_WIDTH 10


typedef struct {
	bool isFull;
	Color color;
} Pixel;

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
	Color backgroundColor = (Color) {0, 0, 0, 0};
	Init(backgroundColor);
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	Pixel mat[GRID_WIDTH][GRID_HEIGHT];
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			mat[i][j].isFull = false;
			mat[i][j].color = (Color) {0, 0, 0, 255};
		}
	}


	while (!WindowShouldClose()) {
	//Resize
		if (IsWindowResized()) {
			screenWidth = GetScreenWidth();
			screenHeight = GetScreenHeight();
		}
	
	//Drawing
		BeginDrawing();
		
			ClearBackground(backgroundColor);
			DrawRectangleLines(screenWidth/10, screenHeight/10, screenWidth - (screenWidth/10)*2, screenHeight - (screenHeight/10)*2, (Color) {255, 255, 255, 255});
		EndDrawing();
	}
	CloseWindow();

	//De-init
	return 0;
}
