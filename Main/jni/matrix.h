class Matrix{
	private:
		int columns;
		int rows;
		float a[1000][1000];
	public:
		Matrix(int m, int n){
			columns=m;
			rows=n;
		}
		void print(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<columns;j++){
					std::cout<<a[i][j]<<" ";
				}
				std::cout<<"\n";
			}
		}
		void rand_gen(){
			srand(time(0));
			for(int i=0;i<rows;i++){
				for(int j=0;j<columns;j++){
					a[i][j]=float(rand())/float(RAND_MAX);
				}
			}
		}
};
