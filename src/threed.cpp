#include "threed.hpp"

vec2 ndc2screen(vec3f point){

	vec2 origin = {(SCR_WIDTH/2),(SCR_HEIGHT/2)};

	return {(origin.x + int_fast64_t((point.x*origin.x))),(origin.y + int_fast64_t((point.y*origin.y)))};
}

float cameraDistance(vec3f b){
	return sqrt( (b.x-globalCamera.pos.x)*(b.x-globalCamera.pos.x) +
	     	     (b.y-globalCamera.pos.y)*(b.y-globalCamera.pos.y) +
	     	     (b.z-globalCamera.pos.z)*(b.z-globalCamera.pos.z));

}

auto interpEdge(vec3i a, vec3i b, vec3i c){	
	
}


void drawCube(vec3i v0, vec3i v1, vec3i v2, vec3i v3, vec3i v4, vec3i v5, vec3i v6, vec3i v7, vec3i v8){
	


}
