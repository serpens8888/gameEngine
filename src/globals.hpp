#ifndef __GLOBALS_HPP
#define __GLOBALS_HPP

#include "headers.hpp"

void SDLInit();

extern SDL_Window * window;

void windowInit();

void windowCheck();

extern SDL_Renderer * renderer;

void rendererInit();

void rendererCheck();

struct RGBA{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};


#endif
