#include "headers.hpp"
#include "globals.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color);

void drawFrag(const std::vector<fragment>& frags);

std::vector<SDL_Point> Hline(const uint16_t& x1, const uint16_t& x2, const uint16_t& y);

std::vector<SDL_Point> Vline(const uint16_t& y1, const uint16_t& y2, const uint16_t& x);

std::vector<SDL_Point> rect(const uint16_t& x1, const uint16_t& y1, const uint16_t& x2, const uint16_t& y2);

bool bias(const uint16_t& x1, const uint16_t& y1, const uint16_t& x2, const uint16_t& y2);

int edgeFunction(const uint16_t& x1, const uint16_t& y1, const uint16_t& x2, const uint16_t& y2, const uint16_t& x3, const uint16_t& y3);

std::vector<SDL_Point> tri(const vec2& v0, const vec2& v1, const vec2& v2);

std::vector<fragment> RGBtri(const uint16_t& x1, const uint16_t& y1, const uint16_t& x2, const uint16_t& y2, const uint16_t& x3, const uint16_t& y3);

std::vector<SDL_Point> quad(const vec2& v0, const vec2& v1, const vec2& v2, const vec2& v3);
