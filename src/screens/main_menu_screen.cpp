#include "main_menu_screen.h"

#include "raylib.h"

#include "game/game.h"

namespace MainMenu
{
	void Init()
	{

	}

	void Input()
	{
		if (IsKeyPressed(KEY_ONE))
		{
			CosmicJump::currentScene = CosmicJump::Scenes::Gameplay;
		}

		if (IsKeyPressed(KEY_TWO))
		{
			CosmicJump::currentScene = CosmicJump::Scenes::Credits;
		}
	}

	void Update()
	{

	}

	void Draw()
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("Main Menu!", 0, 0, 24, WHITE);

		EndDrawing();
	}

	void Close()
	{

	}
}