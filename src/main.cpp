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


	for(uint16_t i = 0;i<900;i++){

	SDL_SetRenderDrawColor(renderer, 0,0,0,255);

	SDL_RenderClear(renderer);



			constexpr uint16_t ten = 10;
			uint16_t j = i+192;
			uint16_t k = i+108;
			vec2 a = {i,i};
			vec2 b = {j,i};
			vec2 c = {j,j};
			vec2 d = {i,k};

			draw(quad(a,b,c,d), teal);



	SDL_RenderPresent(renderer);
	sleep(5);	
	
	}



	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
