#include <bits/stdc++.h>
typedef long long ll; 
const ll N = 1e4 + 15, M = 1e6 + 15;
struct edge { ll u, v, w; };
ll n, m, k, c[11], nw[11][N], ans = LLONG_MAX;
std::vector<edge> v, v2;
bool cmp(edge a, edge b) { return a.w < b.w; };
struct UF
{
	ll fa[N], sz[N];
	void init(ll n)
	{
		for (ll i = 1; i <= n; i++)
			fa[i] = i, sz[i] = 1;
	}
	ll Find(ll u) 
	{
		if (fa[u] == u) return u;
		return fa[u] = Find(fa[u]);
	}
	bool is_unioned(ll u, ll v) { return Find(u) == Find(v); }
	void Union(ll u, ll v)
	{
		ll U = Find(u), V = Find(v);
		if (U == V) return;
		if (sz[U] < sz[V]) std::swap(U, V);
		fa[V] = fa[U], sz[U] += sz[V];
	} 
} uf;
void dfs(ll x, ll sum)
{
	if (x > k)
	{
		v = v2, std::sort(v.begin(), v.end(), cmp);
		uf.init(n + 10);
		for (auto e : v)
		{
			if (uf.is_unioned(e.u, e.v)) continue;
			uf.Union(e.u, e.v), sum += e.w;
		}
		ans = std::min(ans, sum);
		return;
	}
	dfs(x + 1, sum);
	for (ll i = 1; i <= n; i++) v2.push_back({i, n + x, nw[x][i]});
	dfs(x + 1, sum + c[x]);
	for (ll i = 1; i <= n; i++) v2.pop_back();
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m >> k;
	for (ll i = 1, a, b, w; i <= m; i++)
	{
		std::cin >> a >> b >> w;
		v.push_back({a, b, w});
	}
	for (ll i = 1; i <= k; i++)
	{
		std::cin >> c[i];
		for (ll j = 1; j <= n; j++) std::cin >> nw[i][j];
	}
	std::sort(v.begin(), v.end(), cmp), uf.init(n);
	for (edge e : v)
	{
		if (uf.is_unioned(e.u, e.v)) continue;
		v2.push_back(e), uf.Union(e.u, e.v);
	}
	dfs(1, 0);
	std::cout << ans;
	return 0;
}
