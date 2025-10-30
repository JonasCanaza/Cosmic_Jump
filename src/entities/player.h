#pragma once

#include "geometry/rectangle.h"

namespace Player
{
	struct Player
	{
		Geometry::Rectangle rectangle;
		float speedX;
		float speedY;
		bool isActive;
	};

	void Draw(Player player);

	Player Create();
	void MoveUp(Player& player, float deltaTime);
	void MoveDown(Player& player, float deltaTime);
}