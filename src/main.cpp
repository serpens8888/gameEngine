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


	auto start = std::chrono::system_clock::now();

	SDL_SetRenderDrawColor(renderer, 180,100,200,255);

	SDL_RenderClear(renderer);

	vec2 a = {0,1080};
	vec2 b = {0,0};
	vec2 c = {1920,0};
	vec2 d = {1920,1080};
	
	draw(quad(a,b,c,d), teal);


	SDL_RenderPresent(renderer);
	
	auto end = std::chrono::system_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
	std::cout << "fps: " << 1000/(float(duration.count())/1000000) << "        ||        " << "ms elapsed this cycle: " << float(duration.count())/1000000 << "\n";
	std::cout << "available threads: " << threadCount << "\n";

	}




	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
