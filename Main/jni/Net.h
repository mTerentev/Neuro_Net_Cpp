class Net{
	private:
		std::vector<std::vector<int> > net;
		std::vector<std::vector<float> > signals;
		std::vector<std::vector<float> > errors;
		float func(float x){
			return 1/(1+exp(-x));
		}
	public:
		Net(int a, int b, int c, int d){
			int k=0;
			std::vector<int> temp;
			for(int j=0;j<a;j++){
				std::vector<int> temp;
				temp.push_back(k);
				k++;
			}
			net.push_back(temp);
			signals.push_back(std::vector<float>(a,0));
			for(int i=0;i<c;i++){
				for(int j=0;j<a;j++){
					std::vector<int> temp;
					temp.push_back(k);
					k++;
				}
				net.push_back(temp);
				signals.push_back(std::vector<float>(d,0));
			}
			for(int j=0;j<a;j++){
				std::vector<int> temp;
				temp.push_back(k);
				k++;
			}
			net.push_back(temp);
			signals.push_back(std::vector<float>(b,0));
			errors=signals;
		}
		void print(int a){
			for(int i=0;i<signals.size();i++){
				for(int j=0;j<signals[i].size();j++){
					if(a==0)std::cout<<net[i][j]<<" ";
					if(a==1)std::cout<<signals[i][j]<<" ";
					if(a==2)std::cout<<errors[i][j]<<" ";
				}
				std::cout<<"\n";
			}
		}
		float forward(std::vector<float> a){
			for(int i=0;i<signals[0].size();i++){
				signals[0][i]=a[i];
			}
			for(int i=1;i<signals.size();i++){
				for(int k=0;k<signals[i].size();k++){
					float s=0;
				}
			}
		}
};
