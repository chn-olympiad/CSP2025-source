#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct arr{int u, v, w;}e[N * 2];
struct ar{int u, v, w, op;}E[N * 2];
int n, m, k, c[N], fa[N], a[12][N];
bool vis[N];
bool cmp(arr l, arr r)
{
	return l.w < r.w;
}
bool cmp2(ar l, ar r)
{
	return l.w < r.w;
}
inline int getf(int x){return fa[x] == x ? x : fa[x] = getf(fa[x]);}
inline int kruscal(int p, int m)
{
	int sum = 0;
	sort (e + 1, e + m + 1, cmp);
	for (register int i = 1;i <= m ;i = -~i)
	{
		int fx = getf(e[i].u), fy = getf(e[i].v);
		if (fx == fy) continue;
		-- p, sum += e[i].w;
		fa[fx] = fy;
		if (!p) break;
	}
	return sum;
}
inline int kruscal2(int p, int m)
{
	int sum = 0;
	sort (E + 1, E + m + 1, cmp2);
	for (register int i = 1;i <= m ;i = -~i)
	{
		int fx = getf(E[i].u), fy = getf(E[i].v);
		if (fx == fy) continue;
		if (E[i].op && !vis[E[i].op])
		{
			vis[E[i].op] = 1;
			sum += e[i].w;
			fa[fx] = fy;
			continue;
		}
		-- p, sum += E[i].w;
		fa[fx] = fy;
		vis[E[i].op] = 1;
		if (!p) break;
	}
	return sum;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (register int i = 1;i <= n + k; i = -~i) fa[i] = i;
	if (k == 0)
	{
		for (register int i = 1;i <= m; i = -~i)
		{
			cin >> e[i].u >> e[i].v >> e[i].w;
		}
	}
	else
	{
		for (register int i = 1;i <= m; i = -~i)
		{
			cin >> E[i].u >> E[i].v >> E[i].w;
			E[i].op = 0;
		}
	}
	if (k == 0)
	{
		int pos = kruscal(n - 1, m);
		cout << pos << "\n";
		return 0;
	}
	else
	{
		for (register int i = 1;i <= k; i = -~i)
		{
			cin >> c[i];
			for (register int j = 1;j <= n; j = -~j)
			{
				cin >> a[i][j];
				E[ ++ m] = {n + i, j, a[i][j] + c[i], i};
			}
		}
		int pos = kruscal2(n - 1, m);
//		for (register int i = 1;i <= k;i = -~i)
//		{
//			if (vis[i]) pos += a[i][i];
//		}
		cout << pos << "\n";
	}
	return 0;
}
