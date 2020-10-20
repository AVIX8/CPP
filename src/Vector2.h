#ifndef VECTOR_h_
#define VECTOR_h_

#include "Window.h"

class Color;

class Vector2
{
private:
    double x;
    double y;
    Color *color;

public:
    Vector2();
    Vector2(double _x, double _y);
    Vector2(double _x, double _y, Color *_color);
    void Init(double _x, double _y, Color *_color);

    Color *GetColor();
    void setColor(Color *_color);

    void Read();
    void Display();

    double Length();
    double Scalar(Vector2 otherVector);
    double Angle(Vector2 otherVector);

    Vector2 operator+(Vector2 otherVector);

    //увеличивает длину вектора на 1 (postfix)
    Vector2 operator++(int);
    //увеличивает длину вектора на 1 (prefix)
    Vector2& operator++();

    Vector2 &Add(Vector2 otherVector);

    void Draw(SDL_Renderer *renderer);
};

#endif