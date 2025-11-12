#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],xr,dz,pm=1,dh,dl,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	xr=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>xr){
			pm++;
		}
	}
	dz=(pm-1)/(2*n)+1;
	pm=pm-(dz-1)*(2*n);
	if(pm<=n){
		r=pm;
		c=(dz-1)*2+1;
	}
	else if(pm>n){
		pm=pm-n;
		r=n-pm+1;
		c=(dz-1)*2+2;
	}
	cout<<c<<' '<<r;
	return 0;
}
