#include<bits/stdc++.h>
using namespace std;
long long n,ma=LLONG_MIN,ans,mod=998244353,a[5010],c[5010][5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=5008;i++) c[i][1]=1,c[i][i]=1;
	for(int i=1;i<=5008;i++)
		for(int j=2;j<=i-1;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma<=1){
		for(int i=n;i>=3;i--) (ans+=c[n+1][i+1])%=mod;
		cout<<ans,exit(0);
	}
	return 0;
}