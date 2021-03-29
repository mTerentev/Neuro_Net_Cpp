class Net{
	private:
		std::vector<std::vector<int> > net;
		std::vector<std::vector<float> > signals;
		std::vector<std::vector<float> > errors;
		float func(float x){
			return 1.0/(1.0+exp(-x));
		}
		float dfunc(float x){
			return x*(1.0-x);
		}
		void forward_err(float h){
			for(int i=1;i<net.size();i++){
				for(int j=0;j<net[i].size();j++){
					for(int k=0;k<net[i-1].size();k++){
						weights.add(net[i-1][k],net[i][j],h*signals[i-1][k]*errors[i][j]*dfunc(signals[i][j]));
					}
				}
			}
		}
	public:
	    Matrix weights=Matrix(100,100);
		Net(int a, int b, int c, int d){
			int k=0;
			std::vector<int> temp;
			for(int j=0;j<a;j++){
				temp.push_back(k);
				k++;
			}
			net.push_back(temp);
			signals.push_back(std::vector<float>(a,0));
			for(int i=0;i<c;i++){
				temp.clear();
				for(int j=0;j<d;j++){
					temp.push_back(k);
					k++;
				}
				net.push_back(temp);
				signals.push_back(std::vector<float>(d,0));
			}
			temp.clear();
			for(int j=0;j<a;j++){
				temp.push_back(k);
				k++;
			}
			net.push_back(temp);
			signals.push_back(std::vector<float>(b,0));
			errors=signals;
			weights.rand_gen();
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
			std::cout<<"\n";
		}
		std::vector<float> forward(std::vector<float> a){
			std::vector<float> result;
			for(int i=0;i<net[0].size();i++){
				signals[0][i]=a[i];
			}
			for(int i=1;i<net.size();i++){
				for(int j=0;j<net[i].size();j++){
					float s=0;
					for(int k=0;k<net[i-1].size();k++){
						s+=signals[i-1][k]*weights.get(net[i-1][k],net[i][j]);
					}
					signals[i][j]=func(s);
				}
				signals[i][0]=1;
			}
			for(int i=0; i<net[net.size()-1].size();i++){
				result.push_back(signals[net.size()-1][i]);
			}
			return result;
		}
		void backward(float a, float h){
			for(int i=0;i<net[net.size()-1].size();i++){
				errors[net.size()-1][i]=a;
			}
			for(int i=net.size()-2;i>-1;i--){
				for(int j=0;j<net[i].size();j++){
					float e=0;
					for(int k=0;k<net[i+1].size();k++){
						e+=errors[i+1][k]*weights.get(net[i][j],net[i+1][k]);
					}
					errors[i][j]=e;
				}
			}
			forward_err(h);
		}
};
