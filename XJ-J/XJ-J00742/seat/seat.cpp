#include<bits/stdc++.h>

using namespace std;

int n,m,a[205]={0},r,rh,rx,ry;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			rh=i;
		}
	}
	rh=n*m-rh+1;
	if(rh%n==0){
		ry=rh/n;
	}else{
		ry=int(ceil(rh/n)+1);
	}
	if(ry%2==1){
		rx=rh%n;
		if(rx==0) rx+=n;
	}else{
		if(rh%n==0) rx=1;
		else rx=(n+1-rh%n);
	}
	cout<<ry<<" "<<rx;
	return 0;
}
