#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[10005];
long long b[1005][1005],a[10005];
struct node
{
	int u,v;
	long long val;
}d[2000005];
bool cmp(node x,node y)
{
	return x.val < y.val;
}
int findfa(int now)
{
	if(now == fa[now]) return now;
	return fa[now] = findfa(fa[now]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int u,v,w;m;--m) cin >> u >> v >> w,d[++cnt] = (node){u,v,w};
	for(int i(1);i <= n;++i) for(int j(i+1);j <= n;++j) b[i][j] = 1e18;
	for(int i(1),c;i <= k;++i)
	{
		cin >> c;
		for(int i(1);i <= n;++i) cin >> a[i];
		for(int i(1);i <= n;++i) for(int j(i+1);j <= n;++j) b[i][j] = min(b[i][j],c+a[i]+a[j]);
	}
	for(int i(1);i <= n;++i) for(int j(i+1);j <= n;++j) d[++cnt] = (node){i,j,b[i][j]};
	sort(d+1,d+1+cnt,cmp);
	for(int i(1);i <= n;++i) fa[i] = i;
	int tmp(0);
	long long ans(0);
	for(int i(0);tmp < cnt-1 && i <= cnt;++i)
	{
		if(findfa(d[i].u) == findfa(d[i].v)) continue;
		++tmp,ans += d[i].val;
		fa[findfa(d[i].u)] = findfa(d[i].v);
	}
	cout << ans;
}
