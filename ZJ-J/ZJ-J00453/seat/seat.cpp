#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,di=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			di++;
		}
	}
	c=(di-1)/n+1;
	if(c%2==0){
		r=n+1-(di%n);
	}else{
		r=di%n;
	}
	cout<<c<<' ';
	if(r==0){
		cout<<n;
	}else if(r==n+1){
		cout<<1;
	}else{
		cout<<r;
	}
	return 0;
}
