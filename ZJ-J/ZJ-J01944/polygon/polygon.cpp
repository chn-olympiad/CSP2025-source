#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n;
int maxx=0;
int ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+maxx>maxx*2) ans++;
		if(a[1]+maxx>maxx*2&&a[2]!=a[1]) ans++;
		if(a[1]+a[2]+maxx>maxx*2) ans++;
		cout<<ans;
		return 0;
	}
	cout<<n-2;
	return 0;
}
