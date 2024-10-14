#include <raylib.h>
#include <stdio.h>

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


//Functions

void Init(Color backgroundColor) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1500, 900, "Window");
	ClearBackground(backgroundColor);
	SetTargetFPS(60);
}

void fallBlock(Pixel mat[GRID_WIDTH][GRID_HEIGHT]) {
	bool isStatic = false;
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = GRID_HEIGHT - 1; j >= 0; j--) {
			if (!mat[i][j].isStatic) {
				if (j == GRID_HEIGHT - 1 || mat[i][j+1].isFull)
					isStatic = true;
			}
		}
	}
	if (isStatic) {
		for (int i = 0; i < GRID_WIDTH; i++) {
			for (int j = GRID_HEIGHT - 1; j >= 0; j--) {
				if (!mat[i][j].isStatic) {
					mat[i][j].isStatic = true;
					mat[i][j].isFull = true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < GRID_WIDTH; i++) {
			for (int j = GRID_HEIGHT - 1; j >= 0; j--) {
				if (!mat[i][j].isStatic) {
					mat[i][j+1].isStatic = false;
					mat[i][j+1].color = mat[i][j].color;
					mat[i][j].isStatic = true;
					mat[i][j].color = (Color) {20, 20, 20, 255};
				}
			}
		}
	}
}



//Main

int main() {
	//Init
	float time = 0.;
	float timeBetweenFrames = 0.5;
	int frameCount = 0;
	int score = 0;
	Color backgroundColor = (Color) {10, 10, 10, 255};
	Init(backgroundColor);
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	int pixelSize = screenHeight / GRID_HEIGHT;
	Pixel mat[GRID_WIDTH][GRID_HEIGHT];
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			mat[i][j].isFull = false;
			mat[i][j].isStatic = true;
			mat[i][j].color = (Color) {20, 20, 20, 255};
		}
	}
	mat[2][3].color = MAGENTA;
	mat[2][3].isStatic = false;
	mat[3][2].color = MAGENTA;
	mat[3][2].isStatic = false;
	mat[3][3].color = MAGENTA;
	mat[3][3].isStatic = false;
	mat[3][4].color = MAGENTA;
	mat[3][4].isStatic = false;

	while (!WindowShouldClose()) {
	//Resize
		if (IsWindowResized()) {
			screenWidth = GetScreenWidth();
			screenHeight = GetScreenHeight();
		}
	
	//Variable update
		time += GetFrameTime();
	
	//advance time
		if ((float) (frameCount + 1) * timeBetweenFrames < time) {
			printf("frame %d\n", frameCount);
			fallBlock(mat);
			frameCount++;
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
