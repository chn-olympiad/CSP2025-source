#include<bits/stdc++.h>
using namespace std;
int n,m,a1,ai,ls=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>ai;
		if(ai>a1) ls++;
	}
	c=(ls+n-1)/n;
	if(c%2){
		r=ls%n;
		if(!r) r=n;
	}
	else{
		r=(n-ls%n)+1;
//		cout<<r;
		if(r==n+1) r=1;
	}
//	cout<<n;
	cout<<c<<' '<<r;
	return 0;
} 
