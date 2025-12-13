#pragma once

#include <iostream>

#include "raylib.h"
#include "raymath.h"

class Shape
{
    public:
    Vector2 pos;
    Vector2 originalPos;
    
    float playerSize;
    Color playerColor;
    
    Vector2 mouse;
    
    bool dragging = false;
    Vector2 dragOffset;
    
    Vector2 velocity = {0,0};
    
    bool grabbed = false;

    Shape(float x, float y, float size, Color color);

    void update(float &gravity, Rectangle floor);

    void render();

    void getPos(Vector2 textPos, float fontSize, Color textColor);

    void reset();

    bool isHoveredOver();
};