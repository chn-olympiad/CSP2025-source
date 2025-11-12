#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,answer,a[5010],f[5010],g[5010];
void dfs(int t,int k) {
	if(t>n) {
		int ma=-2e9,ans=0;
		if(k<3) return ;
		for(int i=1;i<=n;i++)
			if(f[i]) {
				ma=max(ma,a[i]);
				ans+=a[i];
			}
		if(k>=3&&ans>2*ma) answer=(answer+1)%mod;
		return ;
	}
	f[t]=1;
	dfs(t+1,k+1);
	f[t]=0;
	dfs(t+1,k);
}
int C(int x,int y) {
	return g[y]/g[x-1]%mod/g[x]%mod;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++)
		g[i]=g[i-1]*g[i]%mod;
	if(n>26) {
		for(int i=3;i<=n;i++)
			answer=(answer+C(i,n))%mod;
		cout<<answer;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<answer;
	return 0;
}
