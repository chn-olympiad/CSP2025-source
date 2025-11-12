#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int read ()
{
	int x = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9')
		w = (ch == '-' ? -1 : w), ch = getchar ();
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar (); 
	return x * w;
}

const int N = 1e4 + 7, M = 1e6 + 7;

int n, m, k, k1, res, val[N], p[N], fa[N], b[11][N];

struct Node
{
	int u, v, w;
}a[M << 1], c[N], d[N * 20]; 

inline bool cmp (Node x, Node y)
{
	return x.w < y.w;
}

int find (int x)
{
	return fa[x] == x ? x : fa[x] = find (fa[x]);
}

signed main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	n = read (), m = read (), k = read ();
	for (int i = 1; i <= m; ++ i)
		a[i].u = read (), a[i].v = read (), a[i].w = read ();
	sort (a + 1, a + m + 1, cmp);
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	for (int i = 1, s = 0; i <= m; ++ i)
	{
		int u = find (a[i].u), v = find (a[i].v);
		if (u == v)
			continue;
		fa[u] = v;
		c[++ s] = a[i];
		res += a[i].w;
		if (s == n - 1)
			break;
	}
	for (int i = 1; i <= k; ++ i)
	{
		val[i] = read ();
		for (int j = 1; j <= n; ++ j)
			b[i][j] = read ();
	}
	for (int i = 1; i <= k; ++ i)
	{
		int s = val[i], cnt = 0;
		for (int j = 1; j < n; ++ j)
			d[++ cnt] = c[j];
		for (int j = 1; j <= n; ++ j)
			d[++ cnt] = {n + 1, j, b[i][j]};
		for (int j = 1; j <= n + 1; ++ j)
			fa[j] = j;
		sort (d + 1, d + cnt + 1, cmp);
		for (int j = 1, ss = 0; j <= cnt; ++ j)
		{
			int u = find (d[j].u), v = find (d[j].v);
			if (u == v)
				continue;
			fa[u] = v;
			++ ss;
			s += d[j].w;
			if (ss == n)
				break;
		}
		if (s < res)
			p[++ k1] = i;
	}
	for (int i = 0; i < (1 << k1); ++ i)
	{
		int s = 0, cnt = 0, id = 0;
		for (int j = 1; j < n; ++ j)
			d[++ cnt] = c[j];
		for (int j = 1; j <= k1; ++ j)
			if (i & (1 << j - 1))
			{
				s += val[p[j]], ++ id;
				for (int _ = 1; _ <= n; ++ _)
					d[++ cnt] = {id + n, _, b[p[j]][_]};
			}
		for (int j = 1; j <= n + id; ++ j)
			fa[j] = j;
		sort (d + 1, d + cnt + 1, cmp);
		for (int j = 1, ss = 0; j <= cnt; ++ j)
		{
			int u = find (d[j].u), v = find (d[j].v);
			if (u == v)
				continue;
			fa[u] = v;
			++ ss;
			s += d[j].w;
			if (ss == n + id - 1)
				break;
		}
		res = min (res, s);
	}
	cout << res << '\n';
	return 0;
}
