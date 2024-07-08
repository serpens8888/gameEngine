#include "math.hpp"




uint64_t access2d(uint64_t cols,uint64_t row, uint64_t col){
	return (row*cols)+col;
}

vec2 flat2d(uint64_t rows, uint64_t cols, uint64_t num){
	return {(num%cols),(num%rows)};
}


std::vector<float> matmul(uint64_t m,uint64_t n,uint64_t i,std::vector<float>& mn, std::vector<float>& ni){
	std::vector<float> mi(m*i);
	for(uint64_t i = 0;i<mi.size();i++){
     		float result = 0;
		for(int j = 0;j<n;j++){
			
     		}
		mi[i] = result;
	}




	return mi;

}
