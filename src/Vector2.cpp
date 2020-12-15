#include "Vector2.h"

#include <stdio.h>
#include <math.h>

#include "Color.h"
#include "Window.h"

Vector2::Vector2() : Vector2(0, 0, new Color(255, 255, 255)) {}

Vector2::Vector2(double _x, double _y) : Vector2(_x, _y, new Color(255, 255, 255)) {}

Vector2::Vector2(double _x, double _y, Color *_color)
{
    x = _x;
    y = _y;
    color = _color;
}

// конструктор копирования
Vector2::Vector2(const Vector2 &v)
{
    printf("[Copy constructor]\n");
    x = v.x;
    y = v.y;
    // color = v.color; //мелкое копирование
    color = new Color(*v.color); // глубокое копирование
}

// Перегрузка оператора присваивания
Vector2 &Vector2::operator=(const Vector2 &v)
{
    printf("[Assignment operator]\n");
    x = v.x;
    y = v.y;
    color = v.color;
    return *this;
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
    while (true)
    {
        std::cout << "Enter x and y: ";
        try
        {
            std::cin >> x >> y;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(INT32_MAX, '\n');
                throw std::runtime_error("Invalid input.");
            }
            break;
        }
        catch (const std::exception &e)
        {
            std::cout << "[!] You have entered incorrect data, please try again.\n";
        }
    }
}

double Vector2::Length()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void Vector2::Display()
{
    printf("<Vector2 (x:%lf, y:%lf), Length: %lf>\n", x, y, Length());
}

double Vector2::Scalar(Vector2 v1, Vector2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double Vector2::Angle(Vector2 v1, Vector2 v2)
{
    if (!v1.Length() || !v2.Length()) return 0;
    double ang = acos(Scalar(v1, v2) / v1.Length() / v2.Length()) / M_PI * 180;
    return fmin(ang, 360 - ang);
}

Vector2 Vector2::operator+(Vector2 otherVector)
{
    Vector2 newVector;
    newVector.x = x + otherVector.x;
    newVector.y = y + otherVector.y;
    return newVector;
}

Vector2 &Vector2::operator++()
{
    double len = Length();
    if (!len) len = 1;
    x += x / len;
    y += y / len;
    return *this;
}

Vector2 Vector2::operator++(int)
{
    Vector2 temp = *this;
    ++*this;
    return temp;
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
    SDL_RenderDrawLine(renderer, 250, 250, (int)(250 + x * 25), (int)(250 + y * -25));

    SDL_RenderPresent(renderer);
}