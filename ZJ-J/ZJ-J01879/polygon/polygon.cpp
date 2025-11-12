#include<bits/stdc++.h>
using namespace std;
long long n,a[5002],f[2][5002],maxn,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<a[1];i++)f[1][i]=1;
	for(int i=2;i<n;i++){
		for(long long j=0;j<=maxn;j++){
			if(j>=a[i])f[i&1][j]=(f[(i-1)&1][j-a[i]]+f[(i-1)&1][j])%998244353;
			else f[i&1][j]=(f[(i-1)&1][0]+f[(i-1)&1][j]+1)%998244353;
		}
		if(i>=2)ans=(ans+f[i&1][a[i+1]])%998244353;
	}
	cout<<ans;
	return 0;
}
