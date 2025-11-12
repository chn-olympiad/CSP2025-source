#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,vis[100005],p[100005],c[100005];
ll ans;
char s[100005];
void dfs(int x) {
	if(x==n+1) {
		int cnt=0,num=0;
		for(int i=1; i<=n; i++) {
			if(s[i]=='0')cnt++;
			else if(cnt>=c[p[i]])cnt++;
			else num++;
		}
		if(num>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i])continue;
		p[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1; i<=n; i++)cin>>c[i];
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
