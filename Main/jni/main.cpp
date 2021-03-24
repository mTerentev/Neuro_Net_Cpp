#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

#include <matrix.h>
#include <net.h>

int main()
{
	Matrix mat(10,5);
	mat.rand_gen();
	Net net = Net(2,1,2,5);
	net.print(0);
}
