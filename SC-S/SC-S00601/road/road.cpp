#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll nn=1e18;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,m,k,minn=nn;cin>>n>>m>>k;
	vector<ll> a(m+1),b(m+1),w(m+1);
	vector<bool> vis(n+1);
	vector<vector<ll>> g(n+1),c(k+1,vector<ll>(n+1));
	for(ll i=1;i<=m&&cin>>a[i]>>b[i]>>w[i];i++)g[a[i]].push_back(b[i]),g[b[i]].push_back(a[i]);
	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=n;j++)cin>>c[i][j];
	function<void(ll,ll,ll)>dfs=[&](ll u,ll ans,ll cnt){
		if(cnt==n)minn=min(minn,ans);
		if(vis[u])return;
		vis[u]=1,cnt++;
		for(ll v:g[u])dfs(v,ans+w[u],cnt);
	};
	for(ll i=1;i<=n;i++)dfs(i,0,1);
	cout<<minn;
	return 0;
}