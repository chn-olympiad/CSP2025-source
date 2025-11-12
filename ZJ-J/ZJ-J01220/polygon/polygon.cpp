#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a[5005],ans;
const int mod=998244353;
void dfs(int now,int tot,int mx,int chose) {
	if(now>n) {
		if(chose>=3&&tot>mx*2) ans++;
		return ;
	}
	dfs(now+1,tot,mx,chose);
	mx=max(mx,a[now]);
	tot+=a[now];
	ans%=mod;
	dfs(now+1,tot,mx,chose+1);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n>25) {
		cout<<0;
		return 0;
	}
	dfs(1,0,-1e9,0);
	cout<<ans;
	return 0;
}
