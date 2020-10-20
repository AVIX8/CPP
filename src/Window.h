#ifndef WINDOW_h_
#define WINDOW_h_

#include <stdio.h>
#include "SDL2/SDL.h"
#include "Vector2.h"

class Window
{
public:
	SDL_Window *window;
	SDL_Renderer *renderer;

	Window(const char *title);

	void Clear();

	void Quit();
};

#endif