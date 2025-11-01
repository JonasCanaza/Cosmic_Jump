#include "main_menu_screen.h"

#include "raylib.h"

#include "game/game.h"
#include "interface/button.h"
#include "game/game_constants.h"
#include "interface/ui_constants.h"

using namespace Game;
using namespace UIConstants;

namespace MainMenu
{
	static const int MAX_BUTTONS = 3;
	static Button::Button buttons[MAX_BUTTONS];
	static std::string buttonNames[MAX_BUTTONS] = { "Play", "Credits", "Exit" };

	static void InitButtons();
	static void DrawButtons();
	static void UpdateButtons();

	void Init()
	{
		InitButtons();
	}

	void Input()
	{

	}

	void Update()
	{
		UpdateButtons();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		BeginDrawing();

		DrawButtons();

		EndDrawing();
	}

	void Close()
	{

	}

	static void InitButtons()
	{
		const float logoStartY = static_cast<float>(SCREEN_HEIGHT) / 2.0f;
		const float buttonsStartY = logoStartY;

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			const float buttonCenterX = SCREEN_WIDTH / 2.0f;
			const float buttonX = buttonCenterX - BUTTON_WIDTH / 2.0f;
			const float buttonY = buttonsStartY + (BUTTON_HEIGHT + BUTTON_MARGIN_Y) * i;

			buttons[i] = Button::Create(buttonX, buttonY, BUTTON_WIDTH, BUTTON_HEIGHT, buttonNames[i]);
		}
	}

	static void DrawButtons()
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			Button::Draw(buttons[i]);
		}
	}

	static void UpdateButtons()
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			Button::Update(buttons[i]);
		}
	}
}