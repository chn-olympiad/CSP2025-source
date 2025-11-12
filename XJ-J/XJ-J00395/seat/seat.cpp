#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,c,r,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	if(a[i]==100){
		c=1;
		r=1;
	}
	if(a[i]==99){
		c=1;
		r=2;
	}
	if(a[i]==98){
		c=2;
		r=2;
	}
	if(a[i]==97){
		c=2;
		r=1;
	}
	if(a[i]<=n*m){
		a[i]=i;
	}
	if(i<=n*m){
		a[i]=n*m-i+1;
	}
}
	cout<<c<<" "<<r;
	return 0;
}
