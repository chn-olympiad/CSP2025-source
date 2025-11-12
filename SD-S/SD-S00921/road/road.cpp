#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll read()
{
	ll res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
struct Edge
{
	ll u, v, w;
	bool operator<(const Edge &other) const
	{
		return w < other.w;
	}
};
vector<Edge> es;
ll c[15], w[15][10005], lj[10005], g[10005];
ll find(ll x)
{
	return (x == g[x] ? x : g[x] = find(g[x]));
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ll n = read(), m = read(), k = read(), ans = 0, fla = 1;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		ll u = read(), v = read(), w = read();
		es.emplace_back(Edge{u, v, w});
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		if (c[i]) fla = 0;
		for (int j = 1; j <= n; j++)
		{
			w[i][j] = read();
			if (w[i][j] == 0)
			{
				lj[i] = j;
			}
		}
	}
	if (fla)
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j != lj[i])
				{
					es.emplace_back(Edge{lj[i], j, w[i][j]});
				}
			}
			
		}
		
	}
	sort(es.begin(), es.end());
	for (auto e : es)
	{
		int gu = find(e.u), gv = find(e.v);
		if (gu != gv)
		{
			g[gu] = gv;
			ans += e.w;
		}
	}
	cout << ans << endl;
	return 0;
}

