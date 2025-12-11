#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "mouse.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;
    float size = 40;


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    Rectangle object(0,0,size,size);

    Vector2 dragOffset;
    bool interacting = false;
    
    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();


        
        BeginDrawing();
        ClearBackground(WHITE);


        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            if (CheckCollisionPointRec(mousePos, object))
            {
                interacting = true;
                dragOffset.x = mousePos.x - object.x;
                dragOffset.y = mousePos.y - object.y;
            }
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) interacting = false;

        if (interacting)
        {
            object.x = mousePos.x - dragOffset.x;
            object.y = mousePos.y - dragOffset.y;
        }

        DrawRectangleRec(object,RED);
        
        EndDrawing();
    }
    return 0;
}