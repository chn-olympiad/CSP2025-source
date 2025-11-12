#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 505;
int n,m,ans;
int s[N],c[N],sum[N];
bool vis[N];
void dfs(int k,int cnt) {
	if(k>n) {
		if(cnt<m) {
			return;
		}
		int cntt=0;
		for(int i=1; i<=n; i++) {
			if(vis[i]==1&&s[i]==1) {
				cntt++;
			}
		}
		if(cntt>=m) {
			ans++;
			ans%=mod;
		}
		return;
	}
	vis[k]=1;
	dfs(k+1,cnt+1);
	vis[k]=0;
	dfs(k+1,cnt);
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		char c;
		cin>>c;
		s[i]=c-'0';
		sum[i]=sum[i-1]+s[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(1,0);
	cout<<ans%mod;
	return 0;
}

