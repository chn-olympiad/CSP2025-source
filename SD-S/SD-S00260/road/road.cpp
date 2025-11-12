# include <bits/stdc++.h>
using namespace std;
# define int long long
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second
const int N = 20005, M = 1000005;

int n, m, k;
struct Edge
{
	int u, v, w;
	bool operator < (const Edge &t) const
	{
		return w < t.w;
	}
} E[M], e[M]; int tot;
struct DSU
{
	int fa[N];
	void init ()
	{
		for (int i = 1; i < N; i ++ )
			fa[i] = i; 
	}
	int find_fa (int u)
	{
		return u == fa[u] ? fa[u] : fa[u] = find_fa (fa[u]);
	}
	bool union_fa (int u, int v)
	{
		u = find_fa (u), v = find_fa (v);
		if (u == v)
			return 0;
		fa[v] = u;
		return 1;
	}
} dsu;
vector <Edge> vec;
int kruskal (int num)
{
	vec.clear ();
	for (int i = 1; i <= tot; i ++ )
		e[i] = E[i];
	sort (e + 1, e + 1 + tot);
	dsu.init ();
	int ans = 0, cnt = 0;
	for (int i = 1; i <= tot; i ++ )
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (dsu.union_fa (u, v))
		{
			ans += w;
			cnt ++ ;
			vec.push_back (e[i]);
			if (cnt == num - 1)
				break;
		}
	}
	return ans;
}
int c[N];
int a[15][N];
signed main ()
{
	freopen ("road.in", "r", stdin); freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ )
	{
		int u, v, w; cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	bool flag = 0;
	for (int i = 1; i <= k; i ++ )
	{
		cin >> c[i];
		if (c[i])
			flag = 1;
		for (int j = 1; j <= n; j ++ )
		{
			cin >> a[i][j];
			if (a[i][j])
				flag = 1;
		}
	}
	if (k == 0)
	{
		cout << kruskal (n) << "\n";
		return 0;
	}
	if (!flag)
	{
		cout << "0\n";
		return 0;
	}
	int res = (int)1e18;
	for (int s = 0; s < (1 << k); s ++ )
	{
		int ans = 0;
		for (int i = 1; i <= k; i ++ )
		{
			if (s >> (i - 1) & 1)
				ans += c[i];
		}
		tot = m;
		int num = n;
		for (int i = 1; i <= k; i ++ )
		{
			if (!(s >> (i - 1) & 1))
				continue;
			num ++ ;
			for (int j = 1; j <= n; j ++ )
				E[ ++ tot] = {i + n, j, a[i][j]};
		}
		ans += kruskal (num);
		res = min (res, ans);
	}
	cout << res << endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 9 2 4
100 1 3 2 4
*/
