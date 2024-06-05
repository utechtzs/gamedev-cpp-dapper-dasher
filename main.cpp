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

	// acceleration due to gravity (pixles/s)/s
	const int gravity = 2'000;

	int velocity = 0;
	bool isInAir = false;

	// pixels/sec
	int jumpVel = -600;

	int frame = 0;
	const float updateTime = 1.0 / 12.0;
	float runningTime = 0;
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		float dT = GetFrameTime();
		runningTime += dT;

		if (scarfyPos.y >= windowHeight - scarfyRect.height) {
			// rect on the ground
			velocity = 0;
			isInAir = false;
		} else {
			// rectangle in the air
			velocity += gravity * dT;
			isInAir = true;
		}

		if (IsKeyPressed(KEY_SPACE) && !isInAir) {
			velocity += jumpVel;
		}

		// update position
		scarfyPos.y += velocity * dT;
		if (runningTime >= updateTime) {
			runningTime = 0.0;
			scarfyRect.x = frame * scarfyRect.width;
			frame++;
			if (frame > 5) {
				frame = 0;
			}
		}
		DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

		EndDrawing();
	}
	UnloadTexture(scarfy);
	CloseWindow();
	return 0;
}