#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 10, maxm = 1e6 + 10, maxk = 20, inf = 1e18;
struct edget
{
	ll u, v, w;
} edge[maxm + maxn * maxk], edge2[maxm + maxn * maxk];
bool operator<(edget lhs, edget rhs)
{
	return lhs.w < rhs.w;
}
ll n, m, k, c[maxk], a[maxk][maxn], ans = inf, fa[maxn + maxk];
ll find(ll x)
{
	if (x != fa[x])
	{
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void dfs(ll id, ll cur, ll cnt)
{
	if (id > k)
	{
		for (ll i = 1; i <= m; i++)
		{
			edge2[i] = edge[i];
		}
		sort(edge2 + 1, edge2 + 1 + m);
		for (ll i = 1; i <= n + k; i++)
		{
			fa[i] = i;
		}
		ll tot = 0;
		for (ll i = 1; i <= m; i++)
		{
			ll fu = find(edge2[i].u), fv = find(edge2[i].v);
			if (fu != fv)
			{
				fa[fu] = fv;
				cur += edge2[i].w;
				if (++tot == n + cnt - 1)
				{
					break;
				}
			}
		}
		ans = min(ans, cur);
		return;
	}
	dfs(id + 1, cur, cnt);
	for (ll i = 1; i <= n; i++)
	{
		edge[++m] = {i, n + id, a[id][i]};
	}
	dfs(id + 1, cur + c[id], cnt + 1);
	m -= n;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for (ll i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (ll j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}