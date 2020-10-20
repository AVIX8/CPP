#include "Color.h"

#include "Vector2.h"
#include "Window.h"

Color::Color()
{
    r = 255;
    g = 255;
    b = 255;
}

Color::Color(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
};

void Color::Display()
{
    printf("<Color r:%d, g:%d, b:%d>\n", r, g, b);
}
