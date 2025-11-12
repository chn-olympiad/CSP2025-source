#include <iostream>
using namespace std;
int a(int b,int c){
	if(b>c){return b;}
	else if(b<c){return c;}
	else if(b==c){return b;}
}
int main(){
	int n=0,b,c=[];
	while(n){
		cin>>n;
		if(n+0==n){
			b=n;
			a(n,b);
			cout<<b<<endl;
			
		}
	}
	return 0;
}

