#ifndef __3D_HPP
#define __3D_HPP

#include "global/globals.hpp"
#include "draw.hpp"



vec2i ndc2screen(vec3f point);

vec3f interpPoint(vec3f point);

std::vector<SDL_Point> interpTri(vec3f a, vec3f b, vec3f c);

void drawCube(vec3i v0, vec3i v1, vec3i v2, vec3i v3, vec3i v4, vec3i v5, vec3i v6, vec3i v7, vec3i v8);


#endif
