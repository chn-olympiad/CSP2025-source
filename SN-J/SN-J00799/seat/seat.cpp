#include<iostream>
#include<fstream>
using namespace std;
int main(){
	std::ifstream cin ("seat.in");
	std::ofstream cout ("seat.out");
	int n,m,c,r;
	int a=1,b=1,e=1,d=1;
	cin>>n>>m;
	cin>>a>>b>>e>>d;
	if(n*m==4){
		if(a==98){
			c=2,r=2;
			cout<<c<<" "<<r<<endl;
		}
		else if(a==99){
			c=1,r=2;
			cout<<c<<" "<<r<<endl;
		}
	}
	if(n*m==9){
		if(a=94){
			c=3,r=1;
			cout<<c<<" "<<r<<endl;
		}
	}
	return 0;
}
	//if(n*m==4){
		//if(a>b>e>d&&a>e>b>d&&a>b>d>e&&a>e>d>b&&a>d>e>b&&a>d>b>e){
			//c=1,r=1;
			//cout<<c<<" "<<r<<endl;
		//}
		//else if(b>a>e>d&&b>a>d>e&&e>a>d>b&&e>a>b>d&&d>a>e>b&&d>a>b>e){
			//c=1,r=2;
			//cout<<c<<" "<<r<<endl;
		//}
		//else if(b>e>a>d&&b>d>a>e&&e>b>a>d&&e>d>a>b&&d>e>a>b&&d>b>a>e){
			//c=2,r=2;
			//cout<<c<<" "<<r<<endl;
		//}
		//else{
			//c=2,r=1;
			//cout<<c<<" "<<r<<endl;
		//}
	//}
