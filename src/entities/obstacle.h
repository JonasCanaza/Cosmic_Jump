#pragma once

#include "geometry/rectangle.h"

namespace Obstacle
{
	struct Obstacle
	{
		Geometry::Rectangle rectangle;
		float speedX;
		float speedY;
		bool isActive;
	};
}