#ifndef __MATH_HPP
#define __MATH_HPP

#include "data.hpp"
#include "headers.hpp"

vec2i flat2d(int64_t rows, int64_t cols, int64_t num);
float access2d(const std::vector<float>& matrix, uint64_t cols,uint64_t row, uint64_t col);
float dotProd(std::vector<float> a, std::vector<float> b);
std::vector<float> matmul(uint64_t m,uint64_t n,uint64_t i,const std::vector<float>& mn,const std::vector<float>& ni);





#endif
