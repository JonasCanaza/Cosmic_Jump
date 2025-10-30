#include "game/game.h"

#include <ctime>

#include "raylib.h"

#include "game/game_constants.h"
#include "screens/gameplay_screen.h"

using namespace Game;

namespace CosmicJump
{
	void Play()
	{
		srand(static_cast<unsigned int>(time(0)));

		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME.c_str());
		Gameplay::Init();

		while (!WindowShouldClose())
		{
			Gameplay::Input();
			Gameplay::Update();
			Gameplay::Draw();
		}
	}
}