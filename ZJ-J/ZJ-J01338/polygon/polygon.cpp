//20251101
//10:37 AKed

#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m;
int a[5005];
int f[5005][5005];
int C[5005][5005];
int sum[5005];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	m=a[n];
	for(int i=0;i<=m;++i)if(i<a[1])f[1][i]=1;
	else f[1][i]=2;
	for(int i=2;i<=n;++i){
		for(int j=0;j<a[i];++j)f[i][j]=f[i-1][j];
		for(int j=a[i];j<=m;++j)f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%mod;
	}
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=n;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		for(int j=0;j<=n;++j)sum[i]=(sum[i]+C[i][j])%mod;
	}
	for(int i=2;i<n;++i){
		ans=((ans+sum[i]-f[i][a[i+1]])%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}
/*
	hope all oiers:rp++
	
	I think this CSP is too ez,there will be many AKers.
	So maybe it > 350 ?
	
*/
