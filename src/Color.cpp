#include "Color.h"

#include "Vector2.h"
#include "Window.h"

Color Color::red = Color(255, 0, 0);
Color Color::green = Color(0, 255, 0);
Color Color::blue = Color(0, 0, 255);

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
