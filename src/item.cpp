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

    if (!grabbed)
    {
        velocity.y += gravity * dt;
        pos.y += velocity.y * dt;
        pos.x += velocity.x * dt;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mouse, playerRec))
        {
            grabbed = true;
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
        grabbed = false;
    }

    Rectangle colBox = {pos.x,pos.y,playerSize,playerSize};

    if (CheckCollisionRecs(colBox, floor))
    {
        pos.y = floor.y - playerSize;
        velocity.y = 0;

        float friction = 2000;
        
        if (velocity.x > 0)
        {
            velocity.x -= friction * dt;
            if (velocity.x < 0) velocity.x = 0;
        }
        else if (velocity.x < 0)
        {
            velocity.x += friction * dt;
            if (velocity.x > 0) velocity.x = 0;
        }

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

void Shape::reset()
{
    pos = originalPos;
    velocity = {0,0};
    grabbed = false;
}

void Shape::resolveCollisions(std::vector<Shape>& shapes)
{
    for (size_t i = 0; i < shapes.size(); i++)
    {
        Shape& upper = shapes[i];

        if (upper.velocity.y <= 0)
            continue;

        Rectangle upperRect = {
            upper.pos.x, upper.pos.y,
            upper.playerSize, upper.playerSize
        };

        for (size_t j = 0; j < shapes.size(); j++)
        {
            if (i == j) continue;

            Shape& lower = shapes[j];

            Rectangle lowerRect = {
                lower.pos.x, lower.pos.y,
                lower.playerSize, lower.playerSize
            };

            if (!CheckCollisionRecs(upperRect, lowerRect))
                continue;

            if (upper.pos.y < lower.pos.y)
            {
                // positional correction
                upper.pos.y = lower.pos.y - upper.playerSize;

                // momentum transfer (equal mass)
                lower.velocity.y += upper.velocity.y;
                upper.velocity.y = 0;
            }
        }
    }
}