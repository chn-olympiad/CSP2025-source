#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,zuo=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) zuo++;
	}
	if(zuo%n==0) c=zuo/n;
	else c=zuo/n+1;
	
	if(c%2==1) r=zuo-(c-1)*n;
	else r=c*n-zuo+1;
	cout<<c<<' '<<r;
	return 0;
}
