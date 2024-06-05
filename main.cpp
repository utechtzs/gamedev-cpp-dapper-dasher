#include "raylib.h"

int main() {

	// window setup
	const int windowWidth{512};
	const int windowHeight{380};

	InitWindow(windowWidth, windowHeight, "Dapper Dasher");

	// Scarfy setup
	Texture2D scarfy = LoadTexture("./textures/scarfy.png");
	Rectangle scarfyRect{0.0, 0.0, (float)scarfy.width / 6, (float)scarfy.height};
	Vector2 scarfyPos{windowWidth / 2 - scarfyRect.width / 2, windowHeight - scarfyRect.height};

	// Nebula setup
	Texture2D neb = LoadTexture("./textures/12_nebula_spritesheet.png");
	Rectangle nebRect{0.0, 0.0, (float)neb.width / 8, (float)neb.height / 8};
	Vector2 nebPos{windowWidth, windowHeight - nebRect.height};

	// physics setup
	// acceleration due to gravity (pixles/s)/s
	const int gravity{1'000};
	int velocity{0};
	bool isInAir{false};

	// pixels/sec
	int jumpVel{-600};
	int nebVel{-200};

	// Frame setup
	int frame{0};
	int nebFrame{0};
	const float updateTime{1.0 / 12.0};
	float runningTime{0};

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		float dT = GetFrameTime();

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
		nebPos.x += nebVel * dT;
		if (nebPos.x < 0 - nebRect.width) {
			nebPos.x = windowWidth;
		}

		// update animations
		runningTime += dT;
		if (runningTime >= updateTime) {
			runningTime = 0.0;
			if (!isInAir) {
				scarfyRect.x = frame * scarfyRect.width;
			}
			nebRect.x = nebFrame * nebRect.width;
			frame++;
			nebFrame++;
			if (frame > 5) {
				frame = 0;
			}
			if (nebFrame > 7) {
				nebFrame = 0;
			}
		}

		DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);
		DrawTextureRec(neb, nebRect, nebPos, WHITE);

		EndDrawing();
	}
	UnloadTexture(scarfy);
	UnloadTexture(neb);
	CloseWindow();
	return 0;
}