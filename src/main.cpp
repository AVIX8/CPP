
#include <malloc.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <algorithm>

#include "SDL2/SDL.h"

#include "Vector2.h"
#include "Color.h"
#include "Window.h"

int Script(void *data)
{
    Window *window = (Window *)data;
    window->Clear();
    srand((unsigned)time(0));

    printf("1) Продемонстрировать возврат значения из метода через указатель (*) и через ссылку (&);\n");
    printf("2) Продемонстрировать разумное использование this;\n");
    Vector2 vec1(2, 3, &Color::red);
    printf("vec1 = ");
    vec1.Display();

    Color *red = vec1.GetColor();
    red->Display();

    vec1.Add(vec1).Add(vec1); // <=> vec1 *= 4
    printf("vec1 * 8 = ");
    vec1.Display();

    system("pause");
    system("cls");
    window->Clear();

    printf("3) Создать дружественную функцию и продемонстрировать ее использование;\n");
    vec1.Draw(window->renderer);

    system("pause");
    system("cls");
    window->Clear();

    printf("4) Выполнить перегрузку операторов '+', '++' (два варианта, префиксный и постфиксный). Продемонстрировать в main;\n");
    Vector2 vec2(1, 2, red);

    printf("vec1 = ");
    vec1.Display();
    printf("vec2 = ");
    vec2.Display();

    printf("\n[vec1 + vec2] = ");
    (vec1 + vec2).Display();

    printf("\n[vec1 + vec2++] = ");
    (vec1 + vec2++).Display();

    printf("\nvec1 = ");
    vec1.Display();
    printf("vec2 = ");
    vec2.Display();

    printf("\n[vec1 + ++vec2] = ");
    (vec1 + ++vec2).Display();

    printf("\nvec1 = ");
    vec1.Display();
    printf("vec2 = ");
    vec2.Display();

    system("pause");
    system("cls");
    window->Clear();

    std::string str = "5) Заменить массивы char на std::string, продемонстрировать работу с этим классом;\n";
    printf(str.c_str());

    std::sort(str.begin(), str.end() - 1);
    std::cout << "sorted: " << str;

    system("pause");
    system("cls");
    window->Clear();

    while (1)
    {
        window->Clear();

        Vector2 v1;
        v1.Read();
        v1.setColor(&Color::blue);
        printf("v1 = ");
        v1.Display();
        v1.Draw(window->renderer);

        Vector2 v2;
        v2.Read();
        v2.setColor(&Color::green);
        printf("v2 = ");
        v2.Display();
        v2.Draw(window->renderer);

        printf("Angle between v1 and v2 = %f degrees\n ", Vector2::Angle(v1, v2));

        Vector2 sum = v1 + v2;
        printf("v1 + v2 = ");
        sum.Display();
        sum.setColor(&Color::red);
        sum.Draw(window->renderer);

        printf("\n");
        system("pause");
        system("cls");
    }
}

int main(int argc, char *argv[])
{
    Window *window = new Window("de great prog eve");
    SDL_Thread *thread = SDL_CreateThread(Script, "Script", (void *)window);

    SDL_Event event;
    while (SDL_WaitEvent(&event) >= 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            window->Quit();
            exit(0);
        }
        break;
        }
    }
    return 0;
}