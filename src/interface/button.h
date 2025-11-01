#pragma once

#include <string>

#include "geometry/rectangle.h"

namespace Button
{
    enum class ButtonState
    {
        Normal,
        Hover,
        Pressed
    };

    struct Button
    {
        Geometry::Rectangle rectangle = {};
        std::string text = "";
        ButtonState state = ButtonState::Normal;
        bool clicked = false;
    };

    void Update(Button& button);
    void Draw(Button button);

    Button Create(float x, float y, float width, float height, const std::string& text);
}