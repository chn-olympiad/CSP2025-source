#include<iostream>
using namespace std;

int main(){
	int n,m,a,b,c,d;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		if(a>b&&a>c&&a>>d){
			cout<<1<<endl<<1;
		}
		if(b>a&&b>c&&b>>d){
			cout<<1<<endl<<2;
		}
		if(c>a&&c>b&&c>d){
			cout<<2<<endl<<1;
		}
		if(d>a&&d>b&&d>c){
			cout<<2<<endl<<2;
		}
	}
	return 0;
}

