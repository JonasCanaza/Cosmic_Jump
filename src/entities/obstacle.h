#pragma once

#include "geometry/rectangle.h"

namespace Obstacle
{
	struct Obstacle
	{
		Geometry::Rectangle rectangleTop;
		Geometry::Rectangle rectangleBottom;
		float speedX;
		bool isActive;
	};

	void Update(Obstacle& obstacle, float deltaTime);
	void Draw(Obstacle obstacle);

	Obstacle Create();
}