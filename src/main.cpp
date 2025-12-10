#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "mouse.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    Mouse mouse;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mousePos = mouse.getpos();
        std::cout << "Mouse:" << mousePos.x << " | "<< mousePos.y << std::endl;

        EndDrawing();
    }
    return 0;
}