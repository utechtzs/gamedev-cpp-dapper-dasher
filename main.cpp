#include "raylib.h"

int main() {
	const int DELTA_V = 1;
	const int windowWidth = 800;
	const int windowHeight = 1000;
	const int rectWidth = 50;
	const int rectHeight = 80;

	InitWindow(windowWidth, windowHeight, "Dapper Dasher");
	SetTargetFPS(60);

	int posY = windowHeight - rectHeight;
	int velocity = 0;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		posY += velocity;

		DrawRectangle(windowWidth / 2, posY, rectWidth, rectHeight, GREEN);

		if (IsKeyDown(KEY_SPACE)) {
			velocity -= DELTA_V;
			// reset
		} else if (IsKeyDown(KEY_R)) {
			velocity = 0;
			posY = windowHeight - rectHeight;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}