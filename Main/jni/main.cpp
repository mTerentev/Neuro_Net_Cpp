#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrix.h"
#include "Net.h"
#include "environment.h"

int main()
{
	srand(time(0));
	Net net = Net(3,2,2,20);
	Environment env = Environment(20,20,0.5);
	net.print(1);
	env.print(net);
	env.teach(net,1);
	//env.print(net);
	
	int a;
	std::cin>>a;
	//flag
}
