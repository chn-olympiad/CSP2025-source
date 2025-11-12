#include<bits/stdc++.h> 
using namespace std;
int c,r,a[110],s,x,y;
int main(){
	cin>>c>>r;
	s=c*r;
	x=c,y=r;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	freopen("seat.cpp","r","stdin")
	freopen("seat.cpp","w","stdout") 
	}	
	int R=a[1];
	sort(a+1,a+s+1);s
	for(int j=1;j<=s;j++){
		if(a[j]==R){
			cout<<x<<' '<<y;
			break;
		}
		y--;
		if(y==0){
			x--;
			y=r;
		}
	}
	return 0;
}
