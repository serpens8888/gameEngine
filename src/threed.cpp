#include "threed.hpp"

vec2i ndc2screen(vec3f point){

	vec2i origin = {(SCR_WIDTH/2),(SCR_HEIGHT/2)};

	return {(origin.x + int_fast64_t((point.x*origin.x))),(origin.y + int_fast64_t((point.y*origin.y)))};
}

float cameraDistance(vec3f b){
	return sqrt( (b.x-gCam.pos.x)*(b.x-gCam.pos.x) +
	     	     (b.y-gCam.pos.y)*(b.y-gCam.pos.y) +
	     	     (b.z-gCam.pos.z)*(b.z-gCam.pos.z));

}



vec3f interpPoint(vec3f point){	
	std::vector<float> position = {point.x, point.y, point.z, 1.0f}; //position of point with added w value of 1
	std::cout << position[1] << "\n";
	std::vector<float> newPos = matmul(4,4,1,position,projectionMatrix); //matrix multiply by projection matrix
	std::cout << newPos[1] << "\n";
	vec3f ndcPos = {newPos[0]/newPos[3],newPos[1]/newPos[3],newPos[2]/newPos[3]};
	std::cout << ndcPos.x << "\n";

	return ndcPos;
}

std::vector<SDL_Point> interpTri(vec3f a, vec3f b, vec3f c){
	auto A = ndc2screen(interpPoint(a));
	auto B = ndc2screen(interpPoint(b));
	auto C = ndc2screen(interpPoint(c));

	return tri(A,B,C);

}


void drawCube(vec3i v0, vec3i v1, vec3i v2, vec3i v3, vec3i v4, vec3i v5, vec3i v6, vec3i v7, vec3i v8){
	


}
