#ifndef __DRAW_HPP
#define __DRAW_HPP


#include "global/globals.hpp"
#include "global/colors.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color);

void drawFrag(const std::vector<fragment>& frags);

std::vector<SDL_Point> Hline(const uint_fast16_t& x1, const uint_fast16_t& x2, const uint_fast16_t& y);

std::vector<SDL_Point> Vline(const uint_fast16_t& y1, const uint_fast16_t& y2, const uint_fast16_t& x);

std::vector<SDL_Point> rect(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2);

bool bias(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2);

int edgeFunction(const uint_fast16_t& x1, const uint_fast16_t& y1, const uint_fast16_t& x2, const uint_fast16_t& y2, const uint_fast16_t& x3, const uint_fast16_t& y3);

std::vector<SDL_Point> tri(const vec2& v0, const vec2& v1, const vec2& v2);

std::vector<fragment> RGBtri(vec2 v0, vec2 v1, vec2 v2, RGBA col1, RGBA col2, RGBA col3);

std::vector<SDL_Point> quad(const vec2& v0, const vec2& v1, const vec2& v2, const vec2& v3);


#endif
