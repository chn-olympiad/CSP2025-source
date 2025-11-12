#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		int x=1,y=1;
		for(int j=n;j>=n-i+1;j--) x=x*j;
		for(int j=1;j<=i;j++) y=y*j;
		ans=ans+x/y;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}
