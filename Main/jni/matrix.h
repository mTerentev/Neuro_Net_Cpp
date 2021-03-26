class Matrix{
	private:
		int columns;
		int rows;
		float a[100][100];
	public:
		Matrix(int m, int n){
			columns=m;
			rows=n;
		}
		float get(int i, int j){
			return a[i][j];
		}
		void add(int i, int j, float k){
			a[i][j]+=k;
		}
		void print(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<columns;j++){
					std::cout<<a[j][i]<<" ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
		}
		void rand_gen(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<columns;j++){
					a[i][j]=pow(-1,rand()%2)*float(rand())/float(RAND_MAX);
					//a[i][j]=12*i+j;
				}
			}
		}
};
