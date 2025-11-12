#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool all_zero = true;
long long mn = LLONG_MAX;
struct edge
{
	int u, v, w;
} b[1100001], t[1100001];
int c[11];
int a[11][10001];
int f[10011];
int fa(int x)
{
	if (f[x] == x)
		return x;
	return f[x] = fa(f[x]);
}
bool cmp(const edge &x, const edge &y)
{
	return x.w < y.w;
}
long long zxscs(const int &jds, const int &bs)
{
	long long res = 0, zbs = 0;
	for (int i = 1; i <= jds; ++i)
		f[i] = i;
	for (int i = 1; i <= bs; ++i)
	{
		int x = fa(t[i].u);
		int y = fa(t[i].v);
		if (fa(x) == fa(y))
			continue;
		f[x] = f[y];
		res += t[i].w;
		++zbs;
		if (zbs == jds - 1)
			return res;
	}
	return INT_MAX;
}
void dfs(int now, int jds, int ext)
{
	if (now == k + 1)
	{
		memcpy(t, b, sizeof(t));
		sort(t + 1, t + 1 + m + jds * n, cmp);
		mn = min(mn, zxscs(jds + n, m + jds * n) + ext);
		return;
	}
	{
		for (int i = 1; i <= n; ++i)
			b[m + jds * n + i].u = n + now, b[m + jds * n + i].v = i, b[m + jds * n + i].w = a[now][i];
		dfs(now + 1, jds + 1, ext + c[now]);
	}
	dfs(now + 1, jds, ext);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> b[i].u >> b[i].v >> b[i].w;
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		if (c[i])
			all_zero = false;
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j])
				all_zero = false;
		}
	}
	if (all_zero)
		mn = 0;
	else
		dfs(1, 0, 0);
	cout << mn << '\n';
	return 0;
}
