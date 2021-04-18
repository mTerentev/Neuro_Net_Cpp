#ifndef NET
#define NET

#include <vector>

#include "Matrix.h"

class Net{
	private:
		std::vector<std::vector<int> > net;
		std::vector<std::vector<float> > signals;
		std::vector<std::vector<float> > errors;
		float func(float x);
		float dfunc(float x);
		void forward_err(float h);
	public:
	    Matrix weights=Matrix(100,100);
		Net(int a, int b, int c, int d);
		void print(int a);
		std::vector<float> forward(std::vector<float> a);
		void backward(float a, float h);
};
#endif
