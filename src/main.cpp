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

    Rectangle floor = {0,screenHeight-80,screenWidth,80};


    InitWindow(screenWidth, screenHeight, "ThrowPhysics");
    SetTargetFPS(60);

    std::vector<Shape> shapes;

    // shapes.emplace_back(screenWidth/2-size,screenHeight/2-size,size);

    Button resetBtn(10,20,120,40,"Reset");
    Button spawnBtn(10,70,130,40,"Spawn Box");

    while (!WindowShouldClose())
    {

        if (spawnBtn.clicked()) shapes.emplace_back(screenWidth/2-size,screenHeight/2-size,size);

        for (auto& object : shapes) object.update(gravity, floor);

        Shape::resolveCollisions(shapes);

        if (resetBtn.clicked()) for (auto& object : shapes) shapes.clear();

        BeginDrawing();
        ClearBackground(WHITE);

        for (auto& object : shapes) object.render();

        DrawRectangleRec(floor,PURPLE);

        resetBtn.draw();
        spawnBtn.draw();


        EndDrawing();
    }
    return 0;
}