#ifndef __DATA_HPP
#define __DATA_HPP

#include "headers.hpp"

struct RGBA{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct fragment{
	uint_fast16_t x;
	uint_fast16_t y;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct vec2{
	int_fast16_t x;
	int_fast64_t y;
};

struct vec3i{
	int_fast64_t x;
	int_fast64_t y;
	int_fast64_t z;
};

struct vec3f{
	float x;
	float y;
	float z;
};


struct camera{
	vec3f pos;
	float fov;
	float aspect;
	float near;
	float far;
};





#endif
