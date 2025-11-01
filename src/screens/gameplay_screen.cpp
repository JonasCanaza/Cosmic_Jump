#include "screens/gameplay_screen.h"

#include "raylib.h"

#include "game/game.h"
#include "game/game_constants.h"
#include "entities/player.h"
#include "entities/obstacle.h"
#include "collision/collision_manager.h"
#include "interface/button.h"

using namespace Game;
using namespace Collision;

namespace Gameplay
{
	static Player::Player player;
	static Obstacle::Obstacle obstacle;

	static Button::Button button;
	static const std::string buttonName = " | | ";

	static const float BUTTON_WIDTH = 60.0f;
	static const float BUTTON_HEIGHT = 60.0f;
	static const float BUTTON_MARGIN = 10.0f;

	static float deltaTime;

	static void InitButton();
	static void UpdateButton();
	static void DrawButton();
	static void HandleCollisionBetweenPlayerAndObstacle();
	static void DrawVersion();
	static void DrawInputs();
	static void Reset();

	void Init()
	{
		player = Player::Create();
		obstacle = Obstacle::Create();

		InitButton();

		deltaTime = GetFrameTime();
	}

	void Input()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			CosmicJump::currentScene = CosmicJump::Scenes::MainMenu;
		}

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

		UpdateButton();
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		Player::Draw(player);
		Obstacle::Draw(obstacle);

		DrawButton();

		DrawInputs();
		DrawVersion();

		EndDrawing();
	}

	void Close()
	{

	}

	static void InitButton()
	{
		float x = static_cast<float>(SCREEN_WIDTH) - BUTTON_WIDTH - BUTTON_MARGIN;
		float y = BUTTON_MARGIN;

		button = Button::Create(x, y, BUTTON_WIDTH, BUTTON_HEIGHT, buttonName);
	}

	static void UpdateButton()
	{
		Button::Update(button);
	}

	static void DrawButton()
	{
		Button::Draw(button);
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