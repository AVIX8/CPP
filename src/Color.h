#ifndef COLOR_h_
#define COLOR_h_

class Color
{
public:
    int r;
    int g;
    int b;

    Color()
    {
        r = 255;
        g = 255;
        b = 255;
    }

    Color(int _r, int _g, int _b)
    {
        r = _r;
        g = _g;
        b = _b;
    };
};

#endif