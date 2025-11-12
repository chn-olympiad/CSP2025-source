#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,a[510],f[510],g[510];
char str[510];
void dfs(int t) {
	if(t>n) {
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++) {
			if(cnt>=a[g[i]]) {
				cnt++;continue ;
			}
			if(str[i]=='0') cnt++;
			if(str[i]=='1') tot++;
		}
		if(tot>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!f[i]) {
			g[t]=i;
			f[i]=1;
			dfs(t+1);
			f[i]=0;
		}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
20 pts
0.01 MiB
*/
