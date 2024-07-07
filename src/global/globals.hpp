#ifndef __GLOBALS_HPP
#define __GLOBALS_HPP

#include "headers.hpp"

#include "data.hpp" //holds structs
#include "SDLinit.hpp" //holds sdl initialization functions


extern unsigned int threadCount;
const uint_fast64_t SCR_WIDTH = 1919;
const uint_fast64_t SCR_HEIGHT = 1079;


const camera globalCamera = {
	0.0f, 0.0f, 0.0f, // position
	M_PI_4f, //constant for pi/4 as a float, radians for 45 degrees, FOV
	16.0f/9.0f, //aspect ratio 16*9 for 1920*1080
	0.1f, //near plane distance
	100.0f //far plane distance
				
};



#endif
