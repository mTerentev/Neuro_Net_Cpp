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
				if(c)std::cout<<c<<" ";
				else{
					std::vector<float> inp;
					inp.push_back(float(j)/float(x));
					inp.push_back(float(i)/float(y));
					float t=n.forward(inp)[1];
					if(t<0.25)std::cout<<". ";
					else if(t<0.5 && t>=0.25)std::cout<<"- ";
					else if(t<0.75 && t>=0.5)std::cout<<"+ ";
					else std::cout<<"# ";
				}
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl<<std::endl;
	}
	void teach(Net n,float h){
		for(int i=0;i<50;i++){
			float err=0;
			for(int j=0;j<dots.size();j++){
				std::vector<float> inp;
				inp.push_back(float(dots[j][0])/float(x));
				inp.push_back(float(dots[j][1])/float(y));
				float res=n.forward(inp)[1];
				err=dots[j][2]-1-res;
				n.backward(err,h);
				//n.print(1);
			}
			h/=1.1;
			print(n);
		}
	}
};
