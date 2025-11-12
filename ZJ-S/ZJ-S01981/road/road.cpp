#include <bits/stdc++.h>
#define ll long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
using namespace std;
constexpr ll inf = 1ll << 60;
struct edge
{
	ll u, v, w;
	bool operator < (const edge &t) const
	{
		return w < t.w;
	}
};
ll n, m, k;
ll ans;
ll cnt;
ll c[20];
ll w[11000];
ll fa[11000];
ll e[20][11000];
vector<edge> a, g, t;
ll find(ll x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}
int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		a.push_back(edge{u, v, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> e[i][j];
	}
	sort(a.begin(), a.end());
	for (auto x : a)
	{
		ll U = find(x.u), V = find(x.v);
		if (U == V)
			continue;
		ans += x.w;
		cnt++;
		fa[V] = U;
		g.push_back(x);
		if (cnt == n - 1)
			break;
	}
//	cout << ans << '\n';
	for (ll st = 1; st < (1ll << k); st++)
	{
		t.clear();
		for (auto x : g)
			t.push_back(x);
		ll sum = 0;
		for (int i = 1; i <= n; i++)
			w[i] = inf;
		for (ll i = 0; i < k; i++)
			if ((st >> i) & 1)
			{
				sum += c[i + 1];
				for (ll j = 1; j <= n; j++)
					w[j] = min(w[j], e[i + 1][j]);
			}
		for (int i = 1; i <= n; i++)
			t.push_back(edge{n + 1, i, w[i]});
		for (int i = 1; i <= n + 1; i++)
			fa[i] = i;
		sort(t.begin(), t.end());
		for (auto x : t)
		{
			ll U = find(x.u), V = find(x.v);
			if (U == V)
				continue;
			sum += x.w;
			fa[V] = U;
			if (sum >= ans)
				break;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
