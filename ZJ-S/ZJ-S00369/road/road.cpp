#include<bits/stdc++.h>
using namespace std;
const int N = 1.5e6 + 5;
int n, m, k, fa[N], tot, c[N];
long long ans = 1e18;
struct Node {
	int u, v, w, op;
	bool operator < (const Node k1) {return w < k1.w;}
}a[N];

int find (int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find (fa[x]);
}
signed main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[++ tot] = {u, v, w, -1};
	}
	for (int i = 0; i < k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			int w;
			cin >> w;
			a[++ tot] = {i + n + 1, j, w, i};
		}
	}
	sort (a + 1, a + tot + 1);
	for (int s = 0; s < (1 << k); s ++)
	{
		long long res = 0;
		for (int i = 1; i <= n + 30; i ++) fa[i] = i;
		for (int i = 0; i < k; i ++)
		{
			if ((1 << i) & s) res += c[i];
		}
		for (int i = 1; i <= tot; i ++)
		{
			int u = a[i].u, v = a[i].v, w = a[i].w, op = a[i].op;
			if (op == -1 || (1 << op) & s)
			{
				int r1 = find (u), r2 = find (v);
				if (r1 == r2) continue;
				fa[r1] = r2;
				res += w;
			}
		}
		ans = min (ans, res);
	}
	cout << ans;
}
