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


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    Shape Box(100,100,size, RED);
    
    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();


        Box.update(mousePos, gravity);

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectangle(0,500,800,100,PURPLE);

        Box.render();
        Box.IsCollide();

        EndDrawing();
    }
    return 0;
}