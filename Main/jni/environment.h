class Environment{
	int x,y,n;
	std::vector<std::vector<int> > dots;
	int contains(std::vector<std::vector<int> > dots, int x, int y){
		for(int i=0;i<dots.size();i++){
			if(dots[i][0]==x && dots[i][1]==y)return dots[i][2];
		}
		return 0;
	}
	public:
	Environment(int x1, int y1, int n1){
		x=x1;
		y=y1;
		n=n1;
		for(int i=0;i<n;i++){
			int xt=rand()%x;
			int yt=rand()%y;
			if(contains(dots,xt,yt)==0){
			std::vector<int> temp;
			temp.push_back(xt);
			temp.push_back(yt);
			temp.push_back(rand()%2+1);
			dots.push_back(temp);
			}
			else i--;
		}
	}
	void print(Net n){
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				int c=contains(dots,j,i);
				if(c)std::cout<<c;
				else{
					std::vector<float> inp;
					inp.push_back(j/x);
					inp.push_back(i/y);
					float t=n.forward(inp)[0];
					if(t<0.5)std::cout<<"- ";
					else std::cout<<"+ ";
				}
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl<<std::endl;
	}
	void teach(Net n,float h){
		for(int i=0;i<20;i++){
			float err=0;
			for(int j=0;j<dots.size();j++){
				std::vector<float> inp;
				inp.push_back(dots[j][0]/x);
				inp.push_back(dots[j][1]/y);
				float res=n.forward(inp)[0];
				err+=pow((res-dots[j][2]+1),2);
			}
			err/=dots.size();
			std::cout<<err<<std::endl;
			n.backward(err,h);
			print(n);
		}
	}
};
