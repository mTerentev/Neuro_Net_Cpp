#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "matrix.h"
#include "net.h"

int main()
{
	srand(time(0));
	Net net = Net(2,1,2,5);
	net.print(0);
	std::vector<float> b;
	std::vector<float> c;
	for(int t1=0;t1<30;t1++){
		b.clear();
	    b.push_back(float(rand())/float(RAND_MAX));
	    b.push_back(float(rand())/float(RAND_MAX));
		std::cout<<b[0]<<" "<<b[1]<<std::endl;
	    for(int t2=0;t2<30;t2++){
		    c=net.forward(b);
		    net.backward(0.3-c[0],10/(t2+1));
		    std::cout<<c[0]<<"\n";
		}
	}
	int a;
	std::cin>>a;
}
