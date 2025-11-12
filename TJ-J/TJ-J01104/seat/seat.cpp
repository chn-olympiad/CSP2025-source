#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,v=1,x,y,z;
	cin>>n>>m;
	y=n*m;
	cin>>z;
	for(int i=1;i<y;i++){
		cin>>x;
		if(z<x)v++;
	}
	int p=(v-1)/n+1,q=(v-1)%n;
	cout<<p<<' ';
	if(p%2==1){
		cout<<q+1<<endl;
	}else{
		cout<<n-q<<endl;
	}
	
	cout<<endl;
	return 0;
}
