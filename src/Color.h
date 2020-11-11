#ifndef COLOR_h_
#define COLOR_h_

#include "Vector2.h"
#include "Window.h"

class Color
{
private:
    int r;
    int g;
    int b;

public:
    Color();
    Color(int _r, int _g, int _b);
    void Display();

    static Color red;
    static Color green;
    static Color blue;

    friend void Vector2::Draw(SDL_Renderer *);
};

#endif