#include "item.hpp"

Shape::Shape(float x, float y, float size, Color color)
{
    playerColor = color;
    pos = {x, y};
    playerSize = size;
    originalPos = {x, y};
}

void Shape::update(float &gravity, Rectangle floor)
{
    Rectangle playerRec = {pos.x, pos.y, playerSize, playerSize};

    float dt = GetFrameTime();
    
    Vector2 mouse = GetMousePosition();

    if (IsKeyPressed(KEY_R))
    {
        pos = originalPos;
        velocity = {0,0};
        falling = true;
    }


    if (falling)
    {
        velocity.y += gravity * dt;
        pos.x += velocity.x * dt;
        pos.y += velocity.y * dt;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mouse, playerRec))
        {
            falling = false;
            dragging = true;
            dragOffset.x = mouse.x - pos.x;
            dragOffset.y = mouse.y - pos.y;
        }
    }


    if (dragging)
    {
        Vector2 newPos = {mouse.x - dragOffset.x, mouse.y - dragOffset.y};
        velocity = (newPos - pos) / dt;
        pos = newPos;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        dragging = false;
        falling = true;
    }

    Rectangle colBox = {pos.x,pos.y,playerSize,playerSize};

    if (CheckCollisionRecs(colBox, floor))
    {
        pos.y = floor.y - playerSize;
        velocity = {0,0};
        falling = false;
    }
}

void Shape::render()
{
    DrawRectangleV(pos, {playerSize, playerSize}, playerColor);
}

void Shape::getPos(Vector2 textPos, float fontSize, Color textColor)
{
    DrawText(TextFormat("Pos: X=%.1f Y=%.1f",pos.x,pos.y), textPos.x, textPos.y,fontSize,textColor);
}