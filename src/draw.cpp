#include "draw.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color){
	SDL_SetRenderDrawColor(renderer,color.r, color.g,color.b, color.a);
	SDL_RenderDrawPoints(renderer, points.data(), points.size());
}

std::vector<SDL_Point> Hline(uint16_t x1, uint16_t x2, uint16_t y){
	std::vector<SDL_Point> line((x2-x1)+2);
	for(int i = 0;i<=(x2-x1)+1;i++){
     		line[i].x = x1+i;
     		line[i].y = y;
     	}
	return line;
}

std::vector<SDL_Point> Vline(uint16_t y1, uint16_t y2, uint16_t x){
		std::vector<SDL_Point> line((y2-y1)+2);
	for(int i = 0;i<=(y2-y1)+1;i++){
     		line[i].x = x;
     		line[i].y = y1+i;
     	}
	return line;
}

std::vector<SDL_Point> rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){

	std::vector<SDL_Point> rect;
	for(int i = 0;i<=(x2-x1);i++){
		for(int k = 0;k<=(y2-y1);k++){
		rect.push_back({x1+i, y1+k});
		}
	}
	return rect;
}

