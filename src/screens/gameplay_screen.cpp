#include "screens/gameplay_screen.h"

#include "raylib.h"

#include "game/game_constants.h"
#include "entities/player.h"
#include "entities/obstacle.h"
#include "collision/collision_manager.h"

using namespace Game;
using namespace Collision;

namespace Gameplay
{
	static Player::Player player;
	static Obstacle::Obstacle obstacle;

	static float deltaTime;

	static void HandleCollisionBetweenPlayerAndObstacle();
	static void DrawVersion();
	static void DrawInputs();
	static void Reset();

	void Init()
	{
		player = Player::Create();
		obstacle = Obstacle::Create();

		deltaTime = GetFrameTime();
	}

	void Input()
	{
		if (IsKeyDown(KEY_W))
		{
			Player::MoveUp(player, deltaTime);
		}

		if (IsKeyDown(KEY_S))
		{
			Player::MoveDown(player, deltaTime);
		}
	}

	void Update()
	{
		deltaTime = GetFrameTime();

		Obstacle::Update(obstacle, deltaTime);

		HandleCollisionBetweenPlayerAndObstacle();
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		Player::Draw(player);
		Obstacle::Draw(obstacle);

		DrawInputs();
		DrawVersion();

		EndDrawing();
	}

	static void HandleCollisionBetweenPlayerAndObstacle()
	{
		if (CheckCollisionRectangle(player.rectangle, obstacle.rectangleTop) ||
			CheckCollisionRectangle(player.rectangle, obstacle.rectangleBottom))
		{
			Reset();
		}
	}

	static void DrawVersion()
	{
		int textWidth = MeasureText(PROGRAM_VERSION.c_str(), VERSION_TEXT_SIZE);
		int margin = 10;

		int x = SCREEN_WIDTH - textWidth - margin;
		int y = SCREEN_HEIGHT - VERSION_TEXT_SIZE;

		DrawText(PROGRAM_VERSION.c_str(), x, y, VERSION_TEXT_SIZE, WHITE);
	}

	static void DrawInputs()
	{
		std::string text = "Move up: W     |     Move down: S";
		int fontSize = 34;

		int x = SCREEN_WIDTH / 2 - MeasureText(text.c_str(), fontSize) / 2;

		DrawText(text.c_str(), x, 0, fontSize, WHITE);
	}

	static void Reset()
	{
		Player::Reset(player);
		Obstacle::Reset(obstacle);
	}
}