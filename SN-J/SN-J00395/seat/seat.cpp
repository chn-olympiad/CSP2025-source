#include<fstream>
std::ifstream cin("seat.in");
std::ofstream cout("seat.out");
//#include<bits/stdc++.h>

int main(){
	int n=0,m=0,v=0,xx=0;
	cin>>n>>m;
	xx=n*m;
	int c[xx]={},p=0;
	cin>>v;
	c[0]=v;
	for(int i=1;i<xx-1;i++){
		cin>>c[i];
		
	}
	for(int i=0;i<xx-1;i++){
		if(c[i]<c[i+1]){
			p=c[i];
			c[i]=c[i+1];
			c[i+1]=p;	
		}
	}
	for(int i=0;i<xx;i++){
		if(c[i]==v){
			cout<<(1+i)/m+i%m<<' '<<i%m;
			break;
		}
		
	}
}
