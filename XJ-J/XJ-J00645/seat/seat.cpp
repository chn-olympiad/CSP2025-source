#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,j=0;
	int xs=0;
	int s=0,p=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
		if(a[i]>s){
			p++;
		}
		
	}
	if(p%n==0){
		x=p/n;
		
	}
	else{
		x=p/n+1;
		
	}
	if(x%2==0){
		y=n-p%n+1;
	} 
	else{
		if(p%n==0){
			y=n;
		}
		else{
			y=p%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;//3 3 94 95 96 97 98 99 100 93 92
			 
} 
