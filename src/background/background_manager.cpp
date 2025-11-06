#include "background/background_manager.h"

#include "raylib.h"

#include "game/game_constants.h"

using namespace Game;

namespace Background
{
	struct Background
	{
		float x;
		float y;
		Texture texture;
	};

	Background gameplayBack;
	Background gameplayMid;
	Background gameplayFront;

	static float backgroundScale;
	static float limit;

	static void InitBackground();
	static void DrawBackground();

	void Init()
	{
		InitBackground();
	}

	void Update()
	{

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

		gameplayMid.x = 0.0f;
		gameplayMid.y = 0.0f;

		gameplayFront.x = 0.0f;
		gameplayFront.y = 0.0f;

		backgroundScale = static_cast<float>(SCREEN_WIDTH) / static_cast<float>(gameplayBack.texture.width);
		limit = static_cast<float>(gameplayBack.texture.width) * backgroundScale;
	}

	static void DrawBackground()
	{
		Vector2 backPos = { gameplayBack.x, gameplayBack.y };
		Vector2 midPos = { gameplayMid.x, gameplayMid.y };
		Vector2 frontPos = { gameplayFront.x, gameplayFront.y };

		DrawTextureEx(gameplayBack.texture, backPos, 0, backgroundScale, WHITE);
		DrawTextureEx(gameplayMid.texture, midPos, 0, backgroundScale, WHITE);
		DrawTextureEx(gameplayFront.texture, frontPos, 0, backgroundScale, WHITE);
	}
}