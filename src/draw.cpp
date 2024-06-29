#include "draw.hpp"
#include "colors.hpp"

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

bool bias(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){
	if((x1<x2&&y1==y2)||(y1>y2)){ //y is inverted so greater than here really means less than on a regular graph
		return 0;
	}
	return 1;

}

std::vector<SDL_Point> tri(vec2 v0, vec2 v1, vec2 v2){
	std::vector<SDL_Point> tri;
	
	//bounding box
	uint16_t minX = std::min(v0.x, std::min(v1.x,v2.x));
	uint16_t maxX = std::max(v0.x, std::max(v1.x,v2.x));
	uint16_t minY = std::min(v0.y, std::min(v1.y,v2.y));
	uint16_t maxY = std::max(v0.y, std::max(v1.y,v2.y));

	//clip to screen
	minX =	std::max(minX, uint16_t(0));
	maxX =	std::min(maxX, uint16_t(1919));
	minY =	std::max(minY, uint16_t(0));
	maxY =	std::min(maxY, uint16_t(1079));

	//fill rule to only draw top and left edge for clockwise tri, counter clockwise doesnt get drawn
	bool bias0 = bias(v1.x,v1.y,v2.x,v2.y);
	bool bias1 = bias(v2.x,v2.y,v0.x,v0.y);
	bool bias2 = bias(v0.x,v0.y,v1.x,v1.y);
	
	//triangle row and col steps
	int16_t A01 = v0.y - v1.y;
	int16_t B01 = v1.x - v0.x;
	int16_t A12 = v1.y - v2.y;
	int16_t B12 = v2.x - v1.x;
	int16_t A20 = v2.y - v0.y;
	int16_t B20 = v0.x - v2.x;

	//barycentric coords at bounding box origin
	vec2 p = {minX,minY};
	int32_t w0_row = edgeFunction(v1.x,v1.y,v2.x,v2.y,p.x,p.y);
	int32_t w1_row = edgeFunction(v2.x,v2.y,v0.x,v0.y,p.x,p.y);
	int32_t w2_row = edgeFunction(v0.x,v0.y,v1.x,v1.y,p.x,p.y);

	for(p.y = minY;p.y<= maxY;p.y++){
		int32_t w0 = w0_row;
		int32_t w1 = w1_row;
		int32_t w2 = w2_row;

		for(p.x = minX;p.x<=maxX;p.x++){
     			if((w0|w1|w2)>=0){
				tri.push_back({static_cast<int>(p.x), static_cast<int>(p.y)});
     			}
     			
     			w0+=A12;
     			w1+=A20;
     			w2+=A01;
     		}

		w0_row+=B12;
		w1_row+=B20;
		w2_row+=B01;
	}

     				
	return tri;     			
	
}

std::vector<fragment> RGBtri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3){
	std::vector<fragment> tri;
	
	int minX = std::min(x1, std::min(x2,x3));
	int maxX = std::max(x1, std::max(x2,x3));
	int minY = std::min(y1, std::min(y2,y3));
	int maxY = std::max(y1, std::max(y2,y3));

	int p = edgeFunction(x1,y1,x2,y2,x3,y3);

	for(uint16_t y = minY;y<=maxY;y++){
		for(uint16_t x = minX;x<=maxX;x++){
     			int a = edgeFunction(x2,y2,x3,y3,x,y);
     			int b = edgeFunction(x3,y3,x1,y1,x,y);
     			int c = edgeFunction(x1,y1,x2,y2,x,y);

     			if((a|b|c)>=0){
				float w1 = ((float)a/(float)p);
				float w2 = ((float)b/(float)p);
				float w3 = ((float)c/(float)p);

				uint8_t R = red.r*w1+green.r*w2+blue.r*w3;
				uint8_t G = red.g*w1+green.g*w2+blue.g*w3;
				uint8_t B = red.b*w1+green.b*w2+blue.b*w3;

     				tri.push_back({x,y,R,G,B,255});
     			}
     		}
	}
     				
	return tri;     			
	
}






















