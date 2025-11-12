#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,a[1000007],ans=0,maxn=-5,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		x+=a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
	
}
