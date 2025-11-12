#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int xm,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xm) xm=n*m-i+1;
	}
	for(int i=1;i<=m;i++){
		if(xm<=i*n){
			c=i;
			break;
		}
	}
	if(c%2==1) r=xm+n-c*n;
	else r=c*n-xm+1;
	cout<<c<<" "<<r;
	return 0;
}
