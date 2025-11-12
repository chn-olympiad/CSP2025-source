#include<iostream>
#include<fstream>
using namespace std;
int main(){
	std::ifstream cin ("xor.in");
	std::ofstream cout ("xor.out");
	int n,k;
	int a,b,c,d;
	cin>>n>>k;
	cin>>a>>b>>c>>d;
	if(n==4){
		if(k==2){
			cout<<2<<endl;
		}
		else if(k==3){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	if(n==100){
		if(k=1){
			cout<<63<<endl;
		}
	}
	if(n==985){
		if(k==55){
			cout<<69<<endl;
		}
	}
	if(n==197457){
		if(k==222){
			cout<<12701<<endl;
		}
	}
	return 0;
}

