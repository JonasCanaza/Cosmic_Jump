#include "game/game.h"

#include "raylib.h"

#include "game/game_constants.h"
#include "screens/gameplay_screen.h"

using namespace Game;

namespace CosmicJump
{
	void Play()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME.c_str());

		while (!WindowShouldClose())
		{
			Gameplay::Draw();
		}
	}
}