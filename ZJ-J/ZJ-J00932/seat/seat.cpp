#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],maxx,xr,ansh,ansl,xrf;
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	maxx=n*m;
	for(int i=1;i<=maxx;i++){
		cin>>a[i];
	}
	xrf=a[1];
	sort(a+1,a+maxx+1,cmp);
	for(int i=1;i<=maxx;i++){
		if(a[i]==xrf){
			xr=i;
			break;
		}
	}
	if(xr%n==0){
		ansl=xr/n;
	}
	else{
		ansl=xr/n+1;
	}
	if(ansl%2==0){
		ansh=n-(xr%n)+1;
	}
	else {
		ansh=xr%n;
	}
	if(ansh==0){
		ansh=n;
	}
	cout<<ansl<<" "<<ansh<<endl;
	return 0;
}

