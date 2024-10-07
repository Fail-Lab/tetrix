#include <raylib.h>
#include <stdlib.h>
#include <math.h>

void function(){
	printf("Hello world");
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
			DrawRectangle(0, 0, 200, 500, RED);
		EndDrawing();
	}
	CloseWindow();

	//De-init
	return 0;
}
