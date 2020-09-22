#ifndef VECTOR_h_
#define VECTOR_h_

#include <stdio.h>
#include <math.h>
#include "Window.h"
#include "Color.h"

class Vector2
{
public:
    int x;
    int y;
    Color color;

    Vector2()
    {
        Vector2(0,0,Color(255,255,255));
    }

    Vector2(int _x, int _y) {
        Vector2(_x,_y,Color(255,255,255));
    }

    Vector2(int _x, int _y, Color _color)
    {
        x = _x;
        y = _y;
        color = _color;
    }
    
    void Init(int _x, int _y, Color _color)
    {
        x = _x;
        y = _y;
        color = _color;
    }

    void setColor(Color _color) {
        color = _color;
    }

    void Read()
    {
        while (
            printf("Enter x and y: "),
            fflush(stdin),
            2 != scanf("%d%d", &x, &y) &&
            printf("[!] You have entered incorrect data, please try again.\n")
        );
        fflush(stdin);
    }

    double Length()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void Display()
    {
        printf("<Vector2 (x:%d, y:%d), Length: %lf>\n", x, y, Length());
    }

    double Scalar(Vector2 otherVector)
    {
        return x * otherVector.x + y * otherVector.y;
    }

    double Angle(Vector2 otherVector)
    {
        double ang = acos(Scalar(otherVector) / Length() / otherVector.Length()) / M_PI * 180;
        return fmin(ang, 360 - ang);
    }

    Vector2 operator+(Vector2 otherVector)
    {
        Vector2 newVector;
        newVector.x = x + otherVector.x;
        newVector.y = y + otherVector.y;
        return newVector;
    }

};

#endif