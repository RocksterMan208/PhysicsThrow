#include "item.hpp"

Shape::Shape(float x, float y, float size)
{
    playerColor = 
    {
        (unsigned char)GetRandomValue(50,225),
        (unsigned char)GetRandomValue(50,225),
        (unsigned char)GetRandomValue(50,225),
        255
    };
    
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
            velocity.x -= friction * dt * 4250; // this multiplication by 4250 is to make a friction of 1 make it 4250 units :)

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
    const float numberIterations = 4; // note: changing will make the collisions work better, just amplifies "compression" issue.
    
    for (int k = 0; k < numberIterations; k++)
    {
        for (float i = 0; i < shapes.size(); i++)
        {
            for (float j = i + 1; j < shapes.size(); j++)
            {
                shapes[i].resolveCollisionsWith(shapes[j]);
            }
        }
    }
}

// ------------------------------------------------------------
// end of resloveCollisions
// ------------------------------------------------------------

void Shape::resolveCollisionsWith(Shape& other)
{
    float overX = (pos.x < other.pos.x) ? (pos.x + playerSize) - other.pos.x : (other.pos.x + other.playerSize) - pos.x;
    float overY = (pos.y < other.pos.y) ? (pos.y + playerSize) - other.pos.y : (other.pos.y + other.playerSize) - pos.y;

    if (overX <= 0 || overY <= 0) return;

    bool horizontal = overX < overY;

    if (horizontal)
    {
        float push = overX * .5;

        if (pos.x < other.pos.x)
        {
            pos.x -= push;
            other.pos.x += push;
        }
        else
        {
            pos.x += push;
            other.pos.x -= push;
        }
    }
    else
    {
        float push = overY * .5;

        if (pos.y < other.pos.y)
        {
            pos.y -= push;
            other.pos.y += push;

            doFriction(true, 1);
        }
        else
        {
            pos.y += push;
            other.pos.y -= push;

            other.doFriction(true, 1);
        }
    }

    float& v1 = horizontal ? velocity.x : velocity.y;
    float& v2 = horizontal ? other.velocity.x : other.velocity.y;

    float temp = v1;
    v1 = v2;
    v2 = temp;
}



// ------------------------------------------------------------
// end of resolveCollisionsWith
// ------------------------------------------------------------