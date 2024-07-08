#include "math.hpp"




float access2d(uint64_t cols,uint64_t row, uint64_t col){
	return (row*cols)+col;
}

vec2i flat2d(int64_t rows, int64_t cols, int64_t num){
	return {(num%cols),(num%rows)};
}


float dotProd(std::vector<float> a, std::vector<float> b){
	if(a.size()!=b.size()){
		assert("attempted dot product of uneven vectors");
	}
	float product = 0;
	for(int i = 0;i<a.size();i++){
		product+=(a[i]*b[i]);
	}

	return product;
}

std::vector<float> matmul(uint64_t m,uint64_t n,uint64_t i,std::vector<float>& mn, std::vector<float>& ni){
	std::vector<float> mi(m*i);

	std::vector<float>Mline(n);
	std::vector<float>Iline(n);

	for(uint64_t it = 0;it<mi.size();it++){
     		float result;
		vec2i matrixPosition = flat2d(m,i,it);

		for(uint64_t line = 0;line<n;line++){
			Mline[line] = access2d(m, matrixPosition.y, line);
			Iline[line] = access2d(i, line, matrixPosition.x);
		}

		result= dotProd(Mline,Iline);
		mi[it] = result;
	}




	return mi;

}
