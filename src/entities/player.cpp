#include "player.h"

#include "raylib.h"

#include "game/game_constants.h"

using namespace Game;

namespace Player
{
	static const float DEFAULT_X = 200.0f;
	static const float DEFAULT_WIDTH = 75.0f;
	static const float DEFAULT_HEIGHT = 75.0f;
	static const float DEFAULT_SPEED_X = 450.0f;
	static const float DEFAULT_SPEED_Y = 450.0f;

	void Draw(Player player)
	{
		int x = static_cast<int>(player.rectangle.x);
		int y = static_cast<int>(player.rectangle.y);
		int width = static_cast<int>(player.rectangle.width);
		int height = static_cast<int>(player.rectangle.height);

		DrawRectangle(x, y, width, height, GREEN);
	}

	Player Create()
	{
		Player newPlayer = {};

		newPlayer.rectangle.x = DEFAULT_X;
		newPlayer.rectangle.y = static_cast<float>(SCREEN_HEIGHT) / 2.0f - DEFAULT_WIDTH / 2.0f;
		newPlayer.rectangle.width = DEFAULT_WIDTH;
		newPlayer.rectangle.height = DEFAULT_HEIGHT;
		newPlayer.speedX = DEFAULT_SPEED_X;
		newPlayer.speedY = DEFAULT_SPEED_Y;
		newPlayer.isActive = true;

		return newPlayer;
	}

	void Reset(Player& player)
	{
		player.rectangle.x = DEFAULT_X;
		player.rectangle.y = static_cast<float>(SCREEN_HEIGHT) / 2.0f - DEFAULT_WIDTH / 2.0f;
	}

	void MoveUp(Player& player, float deltaTime)
	{
		player.rectangle.y += -DEFAULT_SPEED_Y * deltaTime;
	}

	void MoveDown(Player& player, float deltaTime)
	{
		player.rectangle.y += DEFAULT_SPEED_Y * deltaTime;
	}
}