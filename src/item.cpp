#include "item.hpp"

Shape::Shape(float x, float y, float size, Color color)
{
    playerColor = color;
    pos = {x, y};
    playerSize = size;
}

void Shape::update(Vector2 &mouse)
{
    Rectangle playerRec = {pos.x, pos.y, playerSize, playerSize};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mouse, playerRec))
        {
            dragging = true;
            dragOffset.x = mouse.x - pos.x;
            dragOffset.y = mouse.y - pos.y;
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) dragging = false;

    if (dragging)
    {
        pos.x = mouse.x - dragOffset.x;
        pos.y = mouse.y - dragOffset.y;
    }
}

void Shape::render()
{
    DrawRectangleV(pos, {playerSize, playerSize}, playerColor);
}