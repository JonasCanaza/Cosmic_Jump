#include "screens/gameplay_screen.h"

#include "raylib.h"

#include "game/game_constants.h"

using namespace Game;

namespace Gameplay
{
	static void DrawVersion();

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawVersion();

		EndDrawing();
	}

	static void DrawVersion()
	{
		int textWidth = MeasureText(PROGRAM_VERSION.c_str(), VERSION_TEXT_SIZE);
		int margin = 10;

		int x = SCREEN_WIDTH - textWidth - margin;
		int y = SCREEN_HEIGHT - VERSION_TEXT_SIZE;

		DrawText(PROGRAM_VERSION.c_str(), x, y, VERSION_TEXT_SIZE, WHITE);
	}
}