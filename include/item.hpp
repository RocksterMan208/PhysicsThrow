#pragma once

#include <iostream>

#include "raylib.h"
#include "raymath.h"

class Shape
{
    public:
    Vector2 pos;
    float playerSize;
    Color playerColor;
    Vector2 mouse;
    bool dragging = false;
    Vector2 dragOffset;
    Vector2 velocity;
    bool falling = true;

    Shape(float x, float y, float size, Color color);

    void update(Vector2 &mouse, float &gravity);

    bool IsCollide();

    void render();
};