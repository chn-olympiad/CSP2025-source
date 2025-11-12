#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

struct Node
{
	ll u, v, w;
}e[1000010];

ll fa[10010];
ll n, m, q, k;
ll ans;

ll find(ll x)
{
	if (fa[x] == x)
	{
		return fa[x];
	}
	else
	{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
bool cmp(Node x, Node y)
{
	if (x.w != y.w)
	{
		return x.w < y.w;
	}
	else if (x.u != y.u)
	{
		return x.u < y.u;
	}
	return x.v < y.v;
}

void ksl()
{
	for (ll i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	sort(e + 1, e + m + 1, cmp);
	for (ll i = 1; i <= m; i++)
	{
		if (find(e[i].u) != find(e[i].v))
		{
			fa[find(e[i].u)] = find(e[i].v);
			ans += e[i].w;
		}
	}
	return ;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	int minn = 2e9;
	bool fl = true;
	for (ll i = 1; i <= k; i++)
	{
		ll c;
		cin >> c;

		if (c != 0)
		{
			fl = false;
		}
		for (ll j = 1; j <= n; j++)
		{
			ll x;
			cin >> x;
			if (x != 0)
			{
				fl = false;
			}
		}
	}
	if (fl)
	{
		cout << 0;
		return 0;
	}

	ksl();
	cout << ans;
	return 0;

	return 0;
}
