#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"

#include "item.hpp"
#include "ui.hpp"

int main()
{
    float screenWidth = 800;
    float screenHeight = 600;
    float size = 40;
    float gravity = 981;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "ThrowPhysics");

    Image icon = LoadImage("resources/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    SetTargetFPS(60);

    std::vector<Shape> shapes;

    // shapes.emplace_back(screenWidth/2-size,screenHeight/2-size,size);

    Button resetBtn(10,20,120,40,"Reset");
    Button spawnBtn(10,70,130,40,"Spawn Box");

    while (!WindowShouldClose())
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        Rectangle floor = {0,screenHeight-80,screenWidth,80};


        if (spawnBtn.clicked() || IsKeyPressed(KEY_S)) shapes.emplace_back(screenWidth/2-size,screenHeight/2-size,size);

        for (auto& object : shapes) object.update(gravity, floor);

        Shape::resolveCollisions(shapes);

        if (resetBtn.clicked() || IsKeyPressed(KEY_R)) for (auto& object : shapes) shapes.clear();

        BeginDrawing();
        ClearBackground(WHITE);

        for (auto& object : shapes) object.render();

        DrawRectangleRec(floor, {225, 0 ,225, 255});
        DrawRectangleLinesEx(floor, 5, {255, 255 ,255, 63});

        resetBtn.draw();
        spawnBtn.draw();


        EndDrawing();
    }
    return 0;
}