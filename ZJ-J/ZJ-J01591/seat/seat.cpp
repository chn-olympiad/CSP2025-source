#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],i,j,k,ans,x,y,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	ans=1;
	for(i=2;i<=n*m;i++){
		cin>>a[i];
		if(k<a[i]){
			ans++;
		}
	}
	y=ans/n;
	t=ans%n;
	if(t!=0){
		y++;
	}else{
		t=n;
	}
	if(y%2==0){
		x=n+1-t;
	}else{
		x=t;
	}
	
	cout<<y<<" "<<x;
	return 0;
}


