#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "item.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;
    float size = 40;
    Vector2 mousePos = GetMousePosition();


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    Shape player(100,100,size, RED);
    
    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();

        std::cout << mousePos.x << " || " << mousePos.y << std::endl;

        player.update(mousePos);

        BeginDrawing();
        ClearBackground(WHITE);

        player.render();

        EndDrawing();
    }
    return 0;
}