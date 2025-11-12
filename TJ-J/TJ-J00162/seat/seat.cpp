#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,x=1,y=1;
	cin>>n>>m;
	int a[n*m+4];
	memset(a,0,n*m+4);
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}xr=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(i==n*m-1)y=0;
		if(x%2==1)y++;
		else if(x%2==0)y--;
		if(y>m&&x%2==1){
			x++;
			y=m;
		}else if(y==0&&x%2==0){
			x++;
			y=1;
		}
		if(a[i]==xr){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
} 
