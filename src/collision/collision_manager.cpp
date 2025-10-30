#include "collision_manager.h"

namespace Collision
{
    bool CheckCollisionRectangle(Geometry::Rectangle rect1, Geometry::Rectangle rect2)
    {
        if (rect1.x + rect1.width >= rect2.x &&
            rect1.x <= rect2.x + rect2.width &&
            rect1.y + rect1.height >= rect2.y &&
            rect1.y <= rect2.y + rect2.height)
        {
            return true;
        }

        return false;
    }
}