#include "math_utils.h"

#include <cstdlib>

namespace MathUtils
{
	float GetFloatRandomBetween(float min, float max)
	{
        float randomNormalized = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float range = max - min;
        float randomValue = min + randomNormalized * range;

        return randomValue;
	}
}