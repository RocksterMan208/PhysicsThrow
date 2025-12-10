#pragma once

#include <iostream>

#include "raylib.h"
#include "raymath.h"

class Mouse
{
    public:
    Vector2 mousePos;

    Mouse();
    Vector2 getpos();
};