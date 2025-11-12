#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(a[i]==xr){
			xr=j;
			break;
		}
	}
	int x=(xr+n-1)/n,y=xr%n;
	if(x%2==0){
		if(y!=0)cout<<x<<" "<<n-y+1;
		else cout<<x<<" "<<1;
	}else{
		if(y!=0)cout<<x<<" "<<y;
		else cout<<x<<" "<<n;
	}
	return 0;
}