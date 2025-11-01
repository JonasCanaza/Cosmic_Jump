#include "credits_screen.h"

#include "raylib.h"

#include "game/game.h"
#include "interface/button.h"
#include "game/game_constants.h"
#include "interface/ui_constants.h"

using namespace Game;
using namespace UIConstants;

namespace Credits
{
	static Button::Button button;
	static const std::string buttonName = "Back";

	static void InitButton();
	static void UpdateButton();
	static void DrawButton();

	void Init()
	{
		InitButton();
	}

	void Input()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			CosmicJump::currentScene = CosmicJump::Scenes::MainMenu;
		}
	}

	void Update()
	{
		UpdateButton();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("Credits!", 0, 0, 24, WHITE);
		DrawButton();

		EndDrawing();
	}

	void Close()
	{

	}

	static void InitButton()
	{
		float x = static_cast<float>(SCREEN_WIDTH) / 2.0f - BUTTON_WIDTH / 2.0f;
		float marginY = 10;
		float y = static_cast<float>(SCREEN_HEIGHT) - BUTTON_HEIGHT - marginY;

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
}