#include "item.hpp"

Shape::Shape(float x, float y, float size, Color color)
{
    playerColor = color;
    pos = {x, y};
    playerSize = size;
}

void Shape::update(Vector2 &mouse, float &gravity)
{
    Rectangle playerRec = {pos.x, pos.y, playerSize, playerSize};

    float dt = GetFrameTime();

    if (falling)
    {
        velocity.y += gravity * dt;
        pos.y += velocity.y;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mouse, playerRec))
        {
            falling = false;
            dragging = true;
            dragOffset.x = mouse.x - pos.x;
            dragOffset.y = mouse.y - pos.y;
            velocity = {0,0};
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        dragging = false;
        falling = true;
    }

    if (dragging)
    {
        pos.x = mouse.x - dragOffset.x;
        pos.y = mouse.y - dragOffset.y;
    }
}

bool Shape::IsCollide()
{
    
    return true;
}

void Shape::render()
{
    DrawRectangleV(pos, {playerSize, playerSize}, playerColor);
}