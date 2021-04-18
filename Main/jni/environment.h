#ifndef ENV
#define ENV

#include "Net.h"
class Environment{
	int x,y;
	float r;
	public:
		Environment(int x1, int y1, float r1);
		void print(Net n);
		void teach(Net n,float h);
};

#endif
