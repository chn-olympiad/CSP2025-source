#include<bits/stdc++.h>
using namespace std;
int a[205];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=1,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<a[i]) ans++;
	}
	x=(ans+m-1)/m;	
	y=ans%m;
	if(y==0) y=m;
	if(x%2==0){
		y=m-y+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
