#pragma once
#include "raylib.h"

class Button
{
public:
    Rectangle buttonBox;
    const char* text;
    Color bg;
    Color fg;

    Button(float x, float y, float w, float h, const char* label)
    {
        buttonBox = {x,y,w,h};
        text = label;
        bg = LIGHTGRAY;
        fg = BLACK;
    }

    bool clicked()
    {
        Vector2 mouse = GetMousePosition();
        return CheckCollisionPointRec(mouse, buttonBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }

    void draw()
    {
        DrawRectangleRec(buttonBox, bg);
        DrawRectangleLinesEx(buttonBox, 2, BLACK);
        DrawText(
            text,
            buttonBox.x + 10,
            buttonBox.y + buttonBox.height/2 - 10,
            20,
            fg
        );
    }
};