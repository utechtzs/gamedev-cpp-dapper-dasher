#include "raylib.h"

int main() {
	const int windowWidth = 512;
	const int windowHeight = 380;

	InitWindow(windowWidth, windowHeight, "Dapper Dasher");

	Texture2D scarfy = LoadTexture("./textures/scarfy.png");
	Rectangle scarfyRect;
	scarfyRect.width = scarfy.width / 6;
	scarfyRect.height = scarfy.height;
	scarfyRect.x = 0;
	scarfyRect.y = 0;
	Vector2 scarfyPos;
	scarfyPos.x = windowWidth / 2 - scarfyRect.width / 2;
	scarfyPos.y = windowHeight - scarfyRect.height;

	const int gravity = 1;

	int velocity = 0;
	bool isInAir = false;
	int jumpVel = -22;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		if (scarfyPos.y >= windowHeight - scarfyRect.height) {
			// rect on the ground
			velocity = 0;
			isInAir = false;
		} else {
			// rectangle in the air
			velocity += gravity;
			isInAir = true;
		}

		if (IsKeyPressed(KEY_SPACE) && !isInAir) {
			velocity += jumpVel;
		}

		// reset
		if (IsKeyPressed(KEY_R)) {
			velocity = 0;
			scarfyPos.y = windowHeight - scarfyRect.height;
		}
		// update position
		scarfyPos.y += velocity;

		DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

		EndDrawing();
	}
	UnloadTexture(scarfy);
	CloseWindow();
	return 0;
}