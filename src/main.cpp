
#include <malloc.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <algorithm>

#include "SDL2/SDL.h"

#include "Vector2.h"
#include "Color.h"
#include "Window.h"

void clear(Window*window){
    system("pause");
    system("cls");
    window->Clear();
}

int Script(void *data)
{
    Window *window = (Window *)data;
    window->Clear();
    srand((unsigned)time(0));

    printf("2) �த�������஢��� �맮� ��� ��������஢ ����᪨�� � �������᪨�� ��ꥪ⠬�\n");

    Vector2 s0 = Vector2();
    Vector2 s2 = Vector2(1,2);
    Vector2 s3 = Vector2(1,2, &Color::red);
    s3.Display();
    s3.Draw(window->renderer);

    Vector2* d0 = new Vector2();
    Vector2* d2 = new Vector2(-1,-2);
    Vector2* d3 = new Vector2(-1,-2, &Color::green);
    d3->Display();
    d3->Draw(window->renderer);

    clear(window);
    printf("3) ���樠����஢��� ������让 ���ᨢ ��������஬ � ����� ��ࠬ��஬;\n");
    
    Vector2 arr[6] = {s0, s2, s3, *d0, *d2, *d3};
    for (size_t i = 0; i < 6; i++)
    {
        arr[i].Display();
        arr[i].Draw(window->renderer);
    }

    clear(window);
    printf("4.1) C������ ��������� ����� � ��ॣ�㧪� ������ ��ᢠ������.\n");

    Vector2 a(2,7);

    Vector2 b(a); // ����஢����
    b.Display();
    
    Vector2 c;
    c = a; // ��ᢠ������
    c.Display();

    clear(window);
    printf("4.2) �த�������஢��� ࠧ��稥 ����� ������ � ��㡮��� ����஢�����;\n");
    
    // a.color: <Color r:255, g:255, b:255>
    Vector2 dc(a); 
    a.color->set(255,0,0);
    dc.color->Display();

    // �� ������ ����஢����: "<Color r:255, g:0, b:0>"
    // �� ��㡮��� ����஢����: "<Color r:255, g:255, b:255>"

    clear(window);
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

        printf("Angle between v1 and v2 = %f degrees\n", Vector2::Angle(v1, v2));

        Vector2 sum = v1 + v2;
        printf("v1 + v2 = ");
        sum.Display();
        sum.setColor(&Color::red);
        sum.Draw(window->renderer);

        clear(window);
    }
}

int main(int argc, char *argv[])
{
    Window *window = new Window("");
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