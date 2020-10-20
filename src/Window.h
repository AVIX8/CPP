#ifndef WINDOW_h_
#define WINDOW_h_

#include <iostream>

#include "SDL2/SDL.h"

class Window
{
public:
	SDL_Window *window;
	SDL_Renderer *renderer;

	Window(std::string title);

	void Clear();

	void Quit();
};

#endif