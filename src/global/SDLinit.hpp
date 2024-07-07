#ifndef __SDLINIT_HPP
#define __SDLINIT_HPP

#include "headers.hpp"

void SDLInit();

extern SDL_Window * window;

void windowInit();

void windowCheck();

extern SDL_Renderer * renderer;

void rendererInit();

void rendererCheck();

void sleep(int time);


#endif
