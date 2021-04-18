#ifndef MAT
#define MAT

class Matrix{
	private:
		int columns;
		int rows;
		float a[100][100];
	public:
		Matrix(int m, int n);
		float get(int i, int j);
		void add(int i, int j, float k);
		void print();
		void rand_gen();
};

#endif
