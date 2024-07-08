#ifndef __MATH_HPP
#define __MATH_HPP

#include "global/globals.hpp"

uint64_t access2d(uint64_t cols,uint64_t row, uint64_t col);
std::vector<float> matmul(uint_fast64_t m,uint_fast64_t n,uint_fast64_t i,std::vector<float>& mn, std::vector<float>& ni);





#endif
