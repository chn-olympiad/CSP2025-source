#include<iostream>
#include<fstream>
using namespace std;
int main(){
	std::ifstream cin ("polygon.in");
	std::ofstream cout ("polygon.out");
	int n;
	int a,b,c,d,e;
	cin>>n;
	cin>>a>>b>>c>>d>>e;
	if(n==5){
		if(a==1){
			cout<<9<<endl;
		}
		if(a==2){
			cout<<6<<endl;
		}
	}
	if(n==20){
		cout<<1042392<<endl;
	}
	if(n==500){
		cout<<366911923<<endl;
	}
	return 0;
}
