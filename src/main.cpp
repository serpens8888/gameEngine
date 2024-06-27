#include "headers.hpp"
#include "globals.hpp"
#include "draw.hpp"


int main(){

	SDLInit();
	windowInit();
	windowCheck();
	rendererInit();
	rendererCheck();

	bool quit = false;
	SDL_Event e;
	while(!quit){
		while(SDL_PollEvent(&e) != 0){
			if(e.type == SDL_QUIT){
				quit = true;
			}
		}


	SDL_SetRenderDrawColor(renderer, 0,0,0,255);

	SDL_RenderClear(renderer);

	RGBA white = {255,255,255,255};

	draw(rect(5,5,100,100), white);

	SDL_RenderPresent(renderer);


	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
