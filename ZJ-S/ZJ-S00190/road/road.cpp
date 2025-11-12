#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll CN = 1e4+4,CM = 2e6+6,CK = 12;
ll n,m,k,cnt,ans = 0x3f3f3f3f3f3f3f3f,sum,c[CK],a[CK][CN],fa[CN];
struct Edge
{
	ll u,v,w;
}e[CM];
bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}
ll find(ll x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (ll i = 1;i <= m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (ll i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (ll j = 1;j <= n;j++)
			cin >> a[i][j];
	}
	for (ll i = 0;i < (1<<k);i++)
	{
		sum = 0;
		cnt = m;
		for (ll j = 1;j <= k;j++)
			if (i&(1<<j-1))
			{
				sum += c[j];
				for (ll l = 1;l <= n;l++)
					e[++cnt] = {n+j,l,a[j][l]};
			}
		for (ll j = 1;j <= n+k;j++)
			fa[j] = j;
		sort(e+1,e+cnt+1,cmp);
		for (ll j = 1;j <= cnt;j++)
			if (find(e[j].u) != find(e[j].v))
			{
				sum += e[j].w;
				fa[find(e[j].u)] = find(e[j].v);
			}
		ans = min(ans,sum);
	}
	cout << ans;
	return 0;
}
