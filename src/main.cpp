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

	vec2 a = {100,100};
	vec2 b = {200,000};
	vec2 c = {1000,1000};

	draw(tri(a,b,c), yellow);

	vec2 d = {1000,1000};
	vec2 e = {600,100};
	vec2 f = {1900,300};
	vec2 g = {1800,1050};

	draw(quad(d,e,f,g), green);
	draw(quad(d,e,f,g), red);
	draw(quad(d,e,f,g), blue);

	SDL_RenderPresent(renderer);
	
	auto end = std::chrono::system_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
	std::cout << "cycle duration: " << duration.count() << "\n";

	}




	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

return 0;
}
