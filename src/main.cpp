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

	draw(rect(5,5,100,100), white);
	draw(rect(15,200,80,320), magenta);
	draw(rect(120,800,1400,1000), yellow);
	draw(rect(0,0,5,5), blue);
	draw(rect(800,100,1900,1080), teal);
	draw(rect(300,0,1500,600), red);
	draw(tri(100,500,300,100,500,700),green);

	SDL_RenderPresent(renderer);


	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
