#include "draw.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color){
	SDL_SetRenderDrawColor(renderer,color.r, color.g,color.b, color.a);
	SDL_RenderDrawPoints(renderer, points.data(), points.size());
}

void drawFrag(const std::vector<fragment>& frags){
	for(int i = 0;i<=frags.size();i++){
	SDL_SetRenderDrawColor(renderer,frags[i].r,frags[i].g,frags[i].b,frags[i].a);
	SDL_RenderDrawPoint(renderer, frags[i].x, frags[i].y);
	}
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


int edgeFunction(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3){
	return (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
}

std::vector<SDL_Point> tri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3){
	std::vector<SDL_Point> tri;
	
	int minX = std::min(x1, std::min(x2,x3));
	int maxX = std::max(x1, std::max(x2,x3));
	int minY = std::min(y1, std::min(y2,y3));
	int maxY = std::max(y1, std::max(y2,y3));

	//clip to screen
	minX =	std::max(minX, 0);
	maxX =	std::min(maxX, 1919);
	minY =	std::max(minY, 0);
	maxY =	std::min(maxY, 1079);

	for(int i = minY;i<=maxY;i++){
		for(int k = minX;k<=maxX;k++){
     			int a = edgeFunction(x2,y2,x3,x3,k,i);
     			int b = edgeFunction(x3,y3,x1,x1,k,i);
     			int c = edgeFunction(x1,y1,x2,y2,k,i);

     			if(a>=0 && b>=0 && c>=0){
     				tri.push_back({k,i});
     			}
     		}
	}
     				
	return tri;     			
	
}
























