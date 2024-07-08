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

std::vector<SDL_Point>Hline(const uint_fast16_t& x1, const uint_fast16_t& x2, const uint_fast16_t& y){
	std::vector<SDL_Point> line((x2-x1)+2);
	for(int i = 0;i<=(x2-x1)+1;i++){
     		line[i].x = x1+i;
     		line[i].y = y;
     	}
	return line;
}

std::vector<SDL_Point> Vline(const uint_fast16_t& y1, const uint_fast16_t& y2, const uint_fast16_t& x){
		std::vector<SDL_Point> line((y2-y1)+2);
	for(int i = 0;i<=(y2-y1)+1;i++){
     		line[i].x = x;
     		line[i].y = y1+i;
     	}
	return line;
}

std::vector<SDL_Point> rect(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2){

	std::vector<SDL_Point> rect;
	for(int i = 0;i<=(x2-x1);i++){
		for(int k = 0;k<=(y2-y1);k++){
		rect.push_back({int(x1+i), int(y1+k)});
		}
	}
	return rect;
}


int edgeFunction(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2, const uint_fast16_t& x3, const uint_fast16_t& y3){
	return (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
}

bool bias(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2){
	if((x1<x2&&y1==y2)||(y1>y2)){ //y is inverted so greater than here really means less than on a regular graph
		return 0;
	}
	return 1;

}

std::vector<SDL_Point> tri(const vec2i& v0, const vec2i& v1, const vec2i& v2){

	if(edgeFunction(v0.x,v0.y,v1.x,v1.y,v2.x,v2.y)<0){
		return {};
	}

	std::vector<SDL_Point> tri;	
	//make bounding box and then clip to screen
	const int minX = std::max(int(std::min({v0.x,v1.x,v2.x})), int(0));
	const int maxX = std::min(int(std::max({v0.x,v1.x,v2.x})), int(1919));
	const int minY = std::max(int(std::min({v0.y,v1.y,v2.y})), int(0));
	const int maxY = std::min(int(std::max({v0.y,v1.y,v2.y})), int(1079));

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
	vec2i p = {minX,minY};
	int32_t w0_row = edgeFunction(v1.x,v1.y,v2.x,v2.y,p.x,p.y) - bias0;
	int32_t w1_row = edgeFunction(v2.x,v2.y,v0.x,v0.y,p.x,p.y) - bias1;
	int32_t w2_row = edgeFunction(v0.x,v0.y,v1.x,v1.y,p.x,p.y) - bias2;
	
	//check if pixel is in tri or on top or left edge and color if true
	for(p.y = minY;p.y<= maxY;p.y++){
		int32_t w0 = w0_row;
		int32_t w1 = w1_row;
		int32_t w2 = w2_row;

		for(p.x = minX;p.x<=maxX;p.x++){
     			if((w0|w1|w2)>=0){
				tri.push_back({int(p.x),int(p.y)});
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

/*
std::vector<fragment> RGBtri(vec2i v0, vec2i v1, vec2i v2, RGBA col1, RGBA col2, RGBA col3){
	std::vector<fragment> tri;
	
	const uint_fast16_t minX =	std::max(std::min({v0.x,v1.x,v2.x}), uint_fast16_t(0));
	const uint_fast16_t maxX =	std::min(std::max({v0.x,v1.x,v2.x}), uint_fast16_t(1919));
	const uint_fast16_t minY =	std::max(std::min({v0.y,v1.y,v2.y}), uint_fast16_t(0));
	const uint_fast16_t maxY =	std::min(std::max({v0.y,v1.y,v2.y}), uint_fast16_t(1079));

	int p = edgeFunction(v0.x,v0.y,v1.x,v1.y,v2.x,v2.y);

	for(uint_fast16_t y = minY;y<=maxY;y++){
		for(uint_fast16_t x = minX;x<=maxX;x++){
     			int a = edgeFunction(v1.x,v1.y,v2.x,v2.y,x,y);
     			int b = edgeFunction(v2.x,v2.y,v0.x,v0.y,x,y);
     			int c = edgeFunction(v0.x,v0.y,v1.x,v1.y,x,y);

     			if((a|b|c)>=0){
				float w1 = ((float)a/(float)p);
				float w2 = ((float)b/(float)p);
				float w3 = ((float)c/(float)p);

				uint8_t R = col1.r*w1+col2.r*w2+col3.r*w3;
				uint8_t G = col1.g*w1+col2.g*w2+col3.g*w3;
				uint8_t B = col1.b*w1+col2.b*w2+col3.b*w3;

     				tri.push_back({x,y,R,G,B,255});
     			}
     		}
	}
     				
	return tri;     			
	
}
*/

std::vector<SDL_Point> quad(const vec2i& v0, const vec2i& v1, const vec2i& v2, const vec2i& v3){

	std::vector<SDL_Point> quad;

	int32_t a = edgeFunction(v0.x,v0.y,v2.x,v2.y,v1.x,v1.y);
	int32_t b = edgeFunction(v0.x,v0.y,v2.x,v2.y,v3.x,v3.y);
	int32_t c = edgeFunction(v1.x,v1.y,v3.x,v3.y,v2.x,v2.y);
	int32_t d = edgeFunction(v1.x,v1.y,v3.x,v3.y,v0.x,v0.y);

	if(((a^b)&(c^d))==1){ //check if convex
		std::vector<SDL_Point> triA = tri(v0,v1,v2);
		std::vector<SDL_Point> triB = tri(v0,v2,v3);
		quad.insert(quad.end(), triA.begin(), triA.end());
		quad.insert(quad.end(), triB.begin(), triB.end());
		return quad; //ez quad :)
	}

	//concave branch
	//predicate returns 0 if true 1 if false, XOR sets the concave point to 1 and everything else to 0
	bool aSignDelta = (a < 0)^1;
	bool bSignDelta = (b < 0)^0;
	bool cSignDelta = (c < 0)^1;
	bool dSignDelta = (d < 0)^0;

	uint8_t check = (aSignDelta << 0) | (bSignDelta << 1) | (cSignDelta << 2) | (dSignDelta << 3);

	uint8_t concaveVec = (check > 1) + (check > 3) + (check > 7);
	constexpr int size = 4;
	const std::array<vec2i, size> verts = {v0, v1, v2 ,v3};
	
	std::vector<SDL_Point> triA;
	std::vector<SDL_Point> triB;
	if(concaveVec == 0 || concaveVec == 2){
		triA = tri(v0,v1,v2);
		triB = tri(v0,v2,v3);
		quad.insert(quad.end(), triA.begin(), triA.end());
		quad.insert(quad.end(), triB.begin(), triB.end());
		return quad; //hard quad :(
	}

		triA = tri(v0,v1,v3);
		triB = tri(v3,v1,v2);
		quad.insert(quad.end(), triA.begin(), triA.end());
		quad.insert(quad.end(), triB.begin(), triB.end());
		return quad; //hard quad :(



}



















