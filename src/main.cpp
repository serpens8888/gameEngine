#include "global/globals.hpp"
#include "draw.hpp"
#include "global/colors.hpp"
#include "threed.hpp"


int main(){

	SDLInit();
	windowInit();
	windowCheck();
	rendererInit();
	rendererCheck();


	bool quit = false;

	SDL_Event EvEnT;
	while(!quit){
		while(SDL_PollEvent(&EvEnT) != 0){
			if(EvEnT.type == SDL_QUIT){
				quit = true;
			}
		}

	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderClear(renderer);

	auto start = std::chrono::system_clock::now();
	

	vec3f d = {-1,1,0};
	vec3f e = {0,-1,0};
	vec3f f = {1,1,0};

	vec2 a = ndc2screen(d);
	vec2 b = ndc2screen(e);
	vec2 c = ndc2screen(f);
	
	draw(tri(a,b,c), magenta);
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
