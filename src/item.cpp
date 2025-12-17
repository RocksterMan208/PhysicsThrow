#include "item.hpp"

Shape::Shape(float x, float y, float size, Color color)
{
    playerColor = color;
    pos = {x, y};
    playerSize = size;
    originalPos = {x, y};
}

// ------------------------------------------------------------
// end of constructor
// ------------------------------------------------------------

void Shape::update(float &gravity, Rectangle floor)
{
    Rectangle playerRec = {pos.x, pos.y, playerSize, playerSize};
    onGround = false;

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
        doFriction(true, 1);
    }
}

// ------------------------------------------------------------
// end of update
// ------------------------------------------------------------

void Shape::render()
{
    DrawRectangleV(pos, {playerSize, playerSize}, playerColor);
}

void Shape::getPos(Vector2 textPos, float fontSize, Color textColor)
{
    DrawText(TextFormat("Pos: X=%.1f Y=%.1f",pos.x,pos.y), textPos.x, textPos.y,fontSize,textColor);
}

// ------------------------------------------------------------
// end of render
// ------------------------------------------------------------

void Shape::reset()
{
    pos = originalPos;
    velocity = {0,0};
    grabbed = false;
}

// ------------------------------------------------------------
// end of reset
// ------------------------------------------------------------

void Shape::doFriction(bool doFriction, float friction)
{
    if (doFriction)
    {
        float dt = GetFrameTime();

        if (velocity.x > 0)
        {
            velocity.x -= friction * dt * 4250; // this multiplication by 5000 is to make a friction of 1 make it 500 units :)

            if (velocity.x < 0) velocity.x = 0;
        }
        else if (velocity.x < 0)
        {
            velocity.x += friction * dt * 4250;
            
            if (velocity.x > 0) velocity.x = 0;
        }
    }

}

// ------------------------------------------------------------
// end of doFriction
// ------------------------------------------------------------

void Shape::resolveCollisions(std::vector<Shape>& shapes)
{
    float dt = GetFrameTime();

    // resolving x collisions and applying them.
    
    for (size_t i = 0; i < shapes.size(); i++)
    {
        
        Shape& current = shapes[i];
        Rectangle currentRec = {current.pos.x, current.pos.y, current.playerSize, current.playerSize};

        for (size_t j = 0; j < shapes.size(); j++)
        {
            if (i == j) continue;

            Shape& other = shapes[j];
            Rectangle otherRec = {other.pos.x, other.pos.y, other.playerSize, other.playerSize};

        if (CheckCollisionRecs(currentRec, otherRec))
        {
            if (current.velocity.y > 0 && current.pos.y < other.pos.y)
            {
                current.pos.y = other.pos.y - current.playerSize;
                current.velocity.y = 0;
                current.doFriction(true, 1);
            }
        }
    }
}
    
    // resolving x collisions and apllying them

    for (size_t i = 0; i < shapes.size(); i++)
    {

        Shape& current = shapes[i];
        Rectangle currentRec = {current.pos.x, current.pos.y, current.playerSize, current.playerSize};

        for (size_t j = 0; j < shapes.size(); j++)
        {
            if (i==j) continue;

            Shape& other = shapes[j];
            Rectangle otherRec = {other.pos.x, other.pos.y, other.playerSize, other.playerSize};

            if (!CheckCollisionRecs(currentRec, otherRec)) continue;
            
            if (current.velocity.x > 0 && current.pos.x < other.pos.x)
            {
                current.pos.x = other.pos.x - current.playerSize;
                current.velocity.x = 0;
            }

            if (current.velocity.x < 0 && current.pos.x > other.pos.x)
            {
                current.pos.x = other.pos.x + current.playerSize;
                current.velocity.x = 0;
            }
        }
    }
}

// ------------------------------------------------------------
// end of resloveCollisions
// ------------------------------------------------------------

