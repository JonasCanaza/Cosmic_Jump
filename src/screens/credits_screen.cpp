#include "credits_screen.h"

#include "raylib.h"

#include "game/game.h"

namespace Credits
{
	void Init()
	{

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

	}

	void Draw()
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawText("Credits!", 0, 0, 24, WHITE);

		EndDrawing();
	}

	void Close()
	{

	}
}