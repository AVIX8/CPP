#include "Vector2.h"

#include <stdio.h>
#include <math.h>

#include "Color.h"
#include "Window.h"

Vector2::Vector2()
{
    Vector2(0, 0, new Color(255, 255, 255));
}

Vector2::Vector2(double _x, double _y)
{
    Vector2(_x, _y, new Color(255, 255, 255));
}

Vector2::Vector2(double _x, double _y, Color *_color)
{
    x = _x;
    y = _y;
    color = _color;
}

void Vector2::Init(double _x, double _y, Color *_color)
{
    x = _x;
    y = _y;
    color = _color;
}

Color *Vector2::GetColor()
{
    return color;
}

void Vector2::setColor(Color *_color)
{
    color = _color;
}

void Vector2::Read()
{
    while (
        printf("Enter x and y: "),
        fflush(stdin),
        2 != scanf("%lf%lf", &x, &y) &&
            printf("[!] You have entered incorrect data, please try again.\n"))
        ;
    fflush(stdin);
}

double Vector2::Length()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void Vector2::Display()
{
    printf("<Vector2 (x:%lf, y:%lf), Length: %lf>\n", x, y, Length());
}

double Vector2::Scalar(Vector2 otherVector)
{
    return x * otherVector.x + y * otherVector.y;
}

double Vector2::Angle(Vector2 otherVector)
{
    double ang = acos(Scalar(otherVector) / Length() / otherVector.Length()) / M_PI * 180;
    return fmin(ang, 360 - ang);
}

Vector2 Vector2::operator+(Vector2 otherVector)
{
    Vector2 newVector;
    newVector.x = x + otherVector.x;
    newVector.y = y + otherVector.y;
    return newVector;
}

Vector2 Vector2::operator++(int)
{
    x++;
    y++;
    return *this;
}

Vector2 &Vector2::operator++()
{
    double len = Length();
    x+=x/len;
    y+=y/len;
    return *this;
}

Vector2 &Vector2::Add(Vector2 otherVector)
{
    x = x + otherVector.x;
    y = y + otherVector.y;
    return *this;
}

void Vector2::Draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);
    SDL_RenderDrawLine(renderer, 250, 250, (int)(250 + x * 25),(int)(250 + y * -25));

    SDL_RenderPresent(renderer);
}