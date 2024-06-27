#include "headers.hpp"
#include "globals.hpp"

void draw(const std::vector<SDL_Point>& points, const RGBA& color);

std::vector<SDL_Point> Hline(uint16_t x1, uint16_t x2, uint16_t y);

std::vector<SDL_Point> Vline(uint16_t y1, uint16_t y2, uint16_t x);

std::vector<SDL_Point> rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
