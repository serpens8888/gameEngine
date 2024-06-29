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

void sleep(int time);

struct RGBA{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct fragment{
	uint16_t x;
	uint16_t y;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct vec2{
	uint16_t x;
	uint16_t y;
};


#endif
