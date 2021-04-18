#include <iostream>
#include <cstdlib>
#include <cmath>

#include "matrix.h"

Matrix::Matrix(int m, int n){
	columns=m;
	rows=n;
}
float Matrix::get(int i, int j){
	return a[i][j];
}
void Matrix::add(int i, int j, float k){
	a[i][j]+=k;
}
void Matrix::print(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			std::cout<<a[j][i]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}
void Matrix::rand_gen(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			a[i][j]=pow(-1,rand()%2)*float(rand())/float(RAND_MAX);
			//a[i][j]=12*i+j;
		}
	}
}
