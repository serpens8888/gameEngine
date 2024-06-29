#include "headers.hpp"
#include "globals.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color);

void drawFrag(const std::vector<fragment>& frags);

std::vector<SDL_Point> Hline(uint16_t x1, uint16_t x2, uint16_t y);

std::vector<SDL_Point> Vline(uint16_t y1, uint16_t y2, uint16_t x);

std::vector<SDL_Point> rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

bool bias(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

int edgeFunction(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3);

std::vector<SDL_Point> tri(vec2 v0, vec2 v1, vec2 v2);

std::vector<fragment> RGBtri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3);
