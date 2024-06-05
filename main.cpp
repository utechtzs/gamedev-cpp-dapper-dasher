#include "raylib.h"

int main() {
	const int windowWidth = 512;
	const int windowHeight = 380;

	InitWindow(windowWidth, windowHeight, "Dapper Dasher");

	const int gravity = 1;

	const int rectWidth = 50;
	const int rectHeight = 80;

	int posY = windowHeight - rectHeight;
	int velocity = 0;
	bool isInAir = false;
	int jumpVel = -22;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		if (posY >= windowHeight - rectHeight) {
			// rect on the ground
			velocity = 0;
			isInAir = false;
		} else {
			// rectangle in the air
			velocity += gravity;
			isInAir = true;
		}

		if (IsKeyPressed(KEY_SPACE) && !isInAir) {
			velocity -= jumpVel;
		}

		// reset
		if (IsKeyPressed(KEY_R)) {
			velocity = 0;
			posY = windowHeight - rectHeight;
		}
		// update position
		posY += velocity;

		DrawRectangle(windowWidth / 2, posY, rectWidth, rectHeight, GREEN);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}