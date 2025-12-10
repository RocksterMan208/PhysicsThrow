#include "mouse.hpp"

Mouse::Mouse()
{

};

Vector2 Mouse::getpos()
{
    mousePos = GetMousePosition();
    return mousePos;
}