#include "headers.hpp"
#include "globals.hpp"
#include "draw.hpp"
#include "colors.hpp"


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

	drawFrag(RGBtri(0,1080,960,0,1920,1080));

	SDL_RenderPresent(renderer);


	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
