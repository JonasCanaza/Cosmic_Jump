#include "background/background_manager.h"

#include "raylib.h"

#include "game/game_constants.h"

using namespace Game;

namespace Background
{
	static const float PARALLAX_SPEED_BACK = 45.0f;
	static const float PARALLAX_SPEED_MID = 145.0f;
	static const float PARALLAX_SPEED_FRONT = 360.0f;

	struct Background
	{
		float x;
		float y;
		float speed;
		Texture texture;
	};

	static Background gameplayBack;
	static Background gameplayMid;
	static Background gameplayFront;

	static float backgroundScale;
	static float limit;

	static void InitBackground();
	static void UpdateBackground(float deltaTime);
	static void DrawBackground();

	void Init()
	{
		InitBackground();
	}

	void Update(float deltaTime)
	{
		UpdateBackground(deltaTime);
	}

	void Draw()
	{
		DrawBackground();
	}

	void Close()
	{
		UnloadTexture(gameplayBack.texture);
		UnloadTexture(gameplayMid.texture);
		UnloadTexture(gameplayFront.texture);
	}

	static void InitBackground()
	{
		gameplayBack.texture = LoadTexture("res/textures/backgrounds/gameplay/back.png");
		gameplayMid.texture = LoadTexture("res/textures/backgrounds/gameplay/mid.png");
		gameplayFront.texture = LoadTexture("res/textures/backgrounds/gameplay/front.png");

		gameplayBack.x = 0.0f;
		gameplayBack.y = 0.0f;
		gameplayBack.speed = PARALLAX_SPEED_BACK;

		gameplayMid.x = 0.0f;
		gameplayMid.y = 0.0f;
		gameplayMid.speed = PARALLAX_SPEED_MID;

		gameplayFront.x = 0.0f;
		gameplayFront.y = 0.0f;
		gameplayFront.speed = PARALLAX_SPEED_FRONT;

		backgroundScale = static_cast<float>(SCREEN_WIDTH) / static_cast<float>(gameplayBack.texture.width);
		limit = static_cast<float>(gameplayBack.texture.width) * backgroundScale;
	}

	static void UpdateBackground(float deltaTime)
	{
		gameplayBack.x -= gameplayBack.speed * deltaTime;
		gameplayMid.x -= gameplayMid.speed * deltaTime;
		gameplayFront.x -= gameplayFront.speed * deltaTime;

		if (gameplayBack.x <= -limit)
		{
			gameplayBack.x += limit;
		}

		if (gameplayMid.x <= -limit)
		{
			gameplayMid.x += limit;
		}

		if (gameplayFront.x <= -limit)
		{
			gameplayFront.x += limit;
		}
	}

	static void DrawBackground()
	{
		Vector2 backPosOne = { gameplayBack.x, gameplayBack.y };
		Vector2 backPosTwo = { gameplayBack.x + limit, gameplayBack.y };

		Vector2 midPosOne = { gameplayMid.x, gameplayMid.y };
		Vector2 midPosTwo = { gameplayMid.x + limit, gameplayMid.y };

		Vector2 frontPosOne = { gameplayFront.x, gameplayFront.y };
		Vector2 frontPosTwo = { gameplayFront.x + limit, gameplayFront.y };

		DrawTextureEx(gameplayBack.texture, backPosOne, 0.0f, backgroundScale, WHITE);
		DrawTextureEx(gameplayBack.texture, backPosTwo, 0.0f, backgroundScale, WHITE);

		DrawTextureEx(gameplayMid.texture, midPosOne, 0.0f, backgroundScale, WHITE);
		DrawTextureEx(gameplayMid.texture, midPosTwo, 0.0f, backgroundScale, WHITE);

		DrawTextureEx(gameplayFront.texture, frontPosOne, 0.0f, backgroundScale, WHITE);
		DrawTextureEx(gameplayFront.texture, frontPosTwo, 0.0f, backgroundScale, WHITE);
	}
}