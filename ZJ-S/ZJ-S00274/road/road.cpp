#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 20, M = 2e6 + 20, inf = 1e16;
int n, m, k;
struct node
{int u, v, w;}ee[M], e[M];
int le = 0;
int cmp(node x, node y)
{
	return x.w < y.w;
}
node g[12][M];
int c[12], vis[12];
int fa[N];
int ans = inf, res = 0;
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
	u = find(u), v = find(v);
	u > v ? fa[u] = v : fa[v] = u;
}
void work()
{
	for (int i = 1; i <= n + k; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		int u = find(ee[i].u), v = find(ee[i].v), w = ee[i].w;
		if (u == v) continue;
		merge(u, v);
		e[++ le] = ee[i];
	}
	m = le;
}
node E[M];
int L;
void work2(int x)
{
	L = 0;
	for (int i = 1; i <= k; i ++)
	{
		if (vis[i])
		{
			for (int j = 1; j <= n; j ++) E[++ L] = g[i][j];
		}
	}
	for (int i = 1; i <= m; i ++) E[++ L] = e[i];
	sort(E + 1, E + 1 + L, cmp);
	
	for (int i = 1; i <= n + k; i ++) fa[i] = i;
	for (int i = 1; i <= L; i ++)
	{
		int u = find(E[i].u), v = find(E[i].v), w = E[i].w;
		if (u == v) continue;
		merge(u, v);
		res += w;
	}
}
void solve()
{
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i ++)
	{
		cin >> ee[i].u >> ee[i].v >> ee[i].w;
	}
	sort(ee + 1, ee + 1 + m, cmp);
	work();
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			g[i][j].u = n + i, g[i][j].v = j;
			cin >> g[i][j].w;
		}
	}
	for (int i = 0; i < (1 << k); i ++)
	{
		res = 0;
		for (int j = 1; j <= k; j ++) 
		{
			if (i & (1 << j - 1)) vis[j] = 1, res += c[j];
			else vis[j] = 0;
		}
		work2(i);
		if (res < ans)
		{
			ans = res;
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	int T = 1;
	while (T --) solve();
	return 0;
}

