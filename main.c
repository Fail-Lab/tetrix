#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
