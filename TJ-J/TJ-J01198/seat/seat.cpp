# include<bits/stdc++.h>
using namespace std;
int n,m,a[120],xr,add_xr,c,r;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr) add_xr=i;
	}
	c=(add_xr-1)/n+1;
	if(c%2==0) r=n-add_xr%n+1;
	else r=add_xr%n;
	if(r==0) r=n;
	cout<<c<<' '<<r;
	return 0;
}
