#pragma once

namespace CosmicJump
{
	enum class Scenes
	{
		MainMenu,
		Gameplay,
		Credits
	};

	extern Scenes currentScene;
	extern bool isRunning;

	void Play();
}