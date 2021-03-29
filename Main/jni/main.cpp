#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

#include "matrix.h"
#include "net.h"
#include "environment.h"

int main()
{
	srand(time(0));
	Net net = Net(2,2,1,50);
	Environment env = Environment(20,20,3);
	net.print(1);
	env.print(net);
	env.teach(net,10);
	//env.print(net);
	
	int a;
	std::cin>>a;
        //flag
}
