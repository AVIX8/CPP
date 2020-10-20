#include "Window.h"

#include <stdio.h>

#include "SDL2/SDL.h"
#include "Vector2.h"

Window::Window(const char *title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 25, 501, 501, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::Clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 96, 96, 96, 255);

    for (int x = 0; x <= 500; x += 25)
    {
        SDL_RenderDrawLine(renderer, x, 0, x, 500);
    }

    for (int y = 0; y <= 500; y += 25)
    {
        SDL_RenderDrawLine(renderer, 0, y, 500, y);
    }

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
    SDL_RenderDrawLine(renderer, 250, 0, 250, 500);
    SDL_RenderDrawLine(renderer, 0, 250, 500, 250);

    SDL_RenderPresent(renderer);
}

void Window::Quit()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}