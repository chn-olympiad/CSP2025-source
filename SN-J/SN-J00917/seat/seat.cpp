#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c=1,r=1,x=1,z;
int main(){	
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	for(int i=2;i<=z;i++){
		if(a[1]<a[i]){
			x++;
		}
	}
	if(x/n<2)	c+=x/(n+1);
	else{
		c+=x/n;
	}
	r=x%n;
	if(r==0) r+=2;
	cout<<c<<" "<<r;
}
