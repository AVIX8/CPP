#ifndef VECTOR_h_
#define VECTOR_h_

#include "Window.h"

class Color;

class Vector2
{
private:
    double x;
    double y;
    

public:
    Color *color;
    Vector2();
    Vector2(double _x, double _y);
    Vector2(double _x, double _y, Color *_color);

    Vector2(const Vector2 &v);
    Vector2& operator= (const Vector2 &v);

    Color *GetColor();
    void setColor(Color *_color);

    void Read();
    void Display();

    double Length();
    static double Scalar(Vector2 v1, Vector2 v2);
    static double Angle(Vector2 v1, Vector2 v2);

    Vector2 operator+(Vector2 otherVector);

    //увеличивает длину вектора на 1 (postfix)
    Vector2 operator++(int);
    //увеличивает длину вектора на 1 (prefix)
    Vector2 &operator++();

    Vector2 &Add(Vector2 otherVector);

    void Draw(SDL_Renderer *renderer);
};

#endif