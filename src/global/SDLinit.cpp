
#include "SDLinit.hpp"


void SDLInit(){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		assert("SDL failed to initialize");
	}
}

SDL_Window * window = nullptr;

void windowInit(){
	window = SDL_CreateWindow("WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
}

void windowCheck(){
	if(window ==  nullptr){
		assert("window failed to intitialize");
	}
}

SDL_Renderer * renderer = nullptr;

void rendererInit(){
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void rendererCheck(){
	if(renderer == nullptr){
		assert("renderer failed to initialize");
	}
}

void sleep(int time){
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
};
