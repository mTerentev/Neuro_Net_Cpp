#include <iostream>
#include <vector>
#include <cstdlib>

#include "environment.h"
#include "net.h"

Environment::Environment(int x1, int y1, float r1){
	x=x1;
	y=y1;
	r=r1;
}
void Environment::print(Net n){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			std::vector<float> inp;
			inp.push_back(1);
			inp.push_back(float(j)/float(x));
			inp.push_back(float(i)/float(y));
			float t=n.forward(inp)[1];
			std::cout<<t<<" ";
			//if(t<0.25)std::cout<<".  ";
			//else if(t<0.5 && t>=0.25)std::cout<<"-  ";
			//else if(t<0.75 && t>=0.5)std::cout<<"+ ";
			//else std::cout<<"# ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<std::endl;
}
void Environment::teach(Net n,float h){
	for(int i=0;i<100;i++){
		float rx=(rand()%100)/float(100);
		float ry=(rand()%100)/float(100);
		int ref=0;
		//if((pow(rx-0.5,2.0)+pow(ry-0.5,2.0))<pow(r,2.0)){ref=1;}
		if(rx>ry)ref=0;
		else {ref=1;}
		std::vector<float> inp;
		inp.push_back(1);
		inp.push_back(rx);
		inp.push_back(ry);
		std::cout<<rx<<" "<<ry<<" "<<ref<<"\n";
		float res=n.forward(inp)[1];
		float err=ref-res;
		n.backward(err,h);
		//n.print(1);
	//h/=1.1;
	print(n);
	}
}
