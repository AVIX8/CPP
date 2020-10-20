
#include <malloc.h>
#include <stdlib.h>
#include <ctime>

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
    Vector2 vector(5, 4, new Color(255, 0, 0));
    printf("vector = ");
    vector.Display();

    Color* red = vector.GetColor();
    red->Display();
    
    vector.Add(vector).Add(vector).Add(vector); // <=> vector *= 8
    printf("vector * 8 = ");
    vector.Display();

    system("pause");
    system("cls");
    window->Clear();

    printf("3) Создать дружественную функцию и продемонстрировать ее использование;\n");
    // Vector2 vector(5, 4, Color(255, 0, 0));
    // printf("vector = ");
    // vector.Display();

    // Color* red = vector.GetColor();
    // red->Display();
    
    // vector.Add(vector).Add(vector).Add(vector); // <=> vector *= 8
    // printf("vector * 8 = ");
    // vector.Display();

    // system("pause");
    // system("cls");
    // window->Clear();

    while (1)
    {
        window->Clear();

        Vector2 v1;
        v1.Read();
        v1.setColor(new Color(0, 255, 0));
        printf("v1 = ");
        v1.Display();
        v1.Draw(window->renderer);

        Vector2 v2;
        v2.Read();
        v2.setColor(new Color(0, 255, 0));
        printf("v2 = ");
        v2.Display();
        v2.Draw(window->renderer);

        printf("Angle between v1 and v2: %f\n", v1.Angle(v2));

        Vector2 sum = v1 + v2;
        printf("v1 + v2 = ");
        sum.Display();
        sum.setColor(new Color(255, 0, 0));
        sum.Draw(window->renderer);

        printf("\n");
        system("pause");
        system("cls");
    }
}

int main(int argc, char *argv[])
{
    Window *window = new Window("DA");
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