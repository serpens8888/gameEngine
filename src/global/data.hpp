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

struct vec2i{
	int64_t x;
	int64_t y;
};

struct vec2f{
	float x;
	float y;
};

struct vec3i{
	int64_t x;
	int64_t y;
	int64_t z;
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
