
#include <malloc.h>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>

#include "SDL2/SDL.h"
#include "Window.h"
#include "Vector2.h"
#include "Color.h"

int Script(void *data)
{
    SetConsoleOutputCP(65001);
    Window *window = (Window *)data;
    window->Clear();
    srand((unsigned)time(0));

    //4) В main продемонстрировать работу со статическими объектами вашего класса;
    printf("4) В main продемонстрировать работу со статическими объектами вашего класса;\n");
    Vector2 red(5, 4, Color(255, 0, 0));
    window->Draw(&red);

    system("pause");
    system("cls");
    window->Clear();

    //5) В main продемонстрировать работу с динамическими объектами вашего класса;
    printf("5) В main продемонстрировать работу с динамическими объектами вашего класса;\n");
    Vector2 *green = new Vector2(-2, 2, Color(0, 255, 0));
    window->Draw(green);

    system("pause");
    system("cls");
    window->Clear();
    delete green;

    //6.1) В main продемонстрировать работу с динамическим массивом объектов вашего класса;
    printf("6.1) В main продемонстрировать работу с динамическим массивом объектов вашего класса;\n");
    int n = 10;
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2) * n);
    for (int i = 0; i < n; i++)
        *(ptr + i) = Vector2(
            rand() % 20 - 10,
            rand() % 20 - 10,
            Color(rand() % 255, rand() % 255, rand() % 255));

    for (int i = 0; i < n; i++)
    {
        window->Draw(ptr + i);
        (ptr + i)->Display();
    }

    system("pause");
    system("cls");
    window->Clear();
    free(ptr);

    //6.2) В main продемонстрировать работу с массивом динамических объектов вашего класса;
    printf("6.2) В main продемонстрировать работу с массивом динамических объектов вашего класса;\n");
    int k = 10;
    Vector2 **arr = new Vector2 *[k];
    for (int i = 0; i < k; i++)
        arr[i] = new Vector2(
            rand() % 20 - 10,
            rand() % 20 - 10,
            Color(rand() % 255, rand() % 255, rand() % 255));

    for (int i = 0; i < k; i++)
    {
        window->Draw(arr[i]);
        arr[i]->Display();
    }

    system("pause");
    system("cls");
    window->Clear();
    delete[] arr;

    //7) Продемострировать применение операторов ✅new, ✅delete, ✅delete[];
    //8) Продемострировать применение функций calloc, ✅malloc, realloc, ✅free;
    printf("8) Продемострировать применение функций calloc, ✅malloc, realloc, ✅free;\n");
    Vector2 *callocated = (Vector2 *)calloc(10, sizeof(Vector2));
    callocated[7].Init(1, 2, Color(255, 255, 255));
    Vector2 *reallocated = (Vector2 *)realloc(callocated, 10 * sizeof(Vector2));
    window->Draw(&reallocated[7]);

    system("pause");
    system("cls");
    window->Clear();
    free(callocated);
    free(reallocated);

    while (1)
    {
        window->Clear();

        Vector2 v1;
        v1.Read();
        v1.setColor(Color(0, 255, 0));
        printf("v1 = ");
        v1.Display();
        window->Draw(&v1);

        Vector2 v2;
        v2.Read();
        v2.setColor(Color(0, 255, 0));
        printf("v2 = ");
        v2.Display();
        window->Draw(&v2);

        printf("Angle between v1 and v2: %f\n", v1.Angle(v2));

        Vector2 sum = v1 + v2;
        printf("v1 + v2 = ");
        sum.Display();
        sum.setColor(Color(255, 0, 0));
        window->Draw(&sum);

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