#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "item.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;
    float size = 40;
    float gravity = 981;

    std::string objects = {"Box"};

    Rectangle floor = {0,520,800,80};


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(120);

    Shape Box(100,100,size, RED);

    while (!WindowShouldClose())
    {
        Box.update(gravity,floor);

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectangleRec(floor,PURPLE);

        Box.render();
        Box.reset();
        Box.getPos({0,0},20,BLACK);

        EndDrawing();
    }
    return 0;
}