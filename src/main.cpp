#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "item.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;
    float size = 40;
    float gravity = 10;
    Vector2 mousePos = GetMousePosition();

    Rectangle floor = {0,520,800,80};


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    Shape Box(100,100,size, RED);

    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();


        Box.update(mousePos, gravity,floor);

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectangleRec(floor,PURPLE);

        Box.render();

        EndDrawing();
    }
    return 0;
}