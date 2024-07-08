#include "math.hpp"




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


float access2d(const std::vector<float>& matrix, uint64_t cols,uint64_t row, uint64_t col){
        return matrix[row*cols+col];
}

vec2i flat2d(int64_t rows, int64_t cols, int64_t num){
	return {(num-(num%cols))/cols, num%rows};
}

std::vector<float> matmul(uint64_t m,uint64_t n,uint64_t i,const std::vector<float>& mn,const std::vector<float>& ni){
        std::vector<float> mi(m*i);

        for(uint64_t it = 0;it<mi.size();it++){
                float result = 0.0f;
                vec2i matrixPosition = flat2d(m,i,it);

                for(uint64_t line = 0;line<n;line++){
                	float Mvalue = access2d(mn, m, matrixPosition.x, line);
                        float Ivalue = access2d(ni, i, line, matrixPosition.y);
			result+= Mvalue*Ivalue;
                }

                mi[it] = result;
        }




        return mi;

}


