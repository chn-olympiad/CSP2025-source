#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int fa[10001], c[10001][10001];
struct Edge
{
	int u, v, w;
} e[10000001];
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
int find(int x)
{
	if (fa[x] = x)
	{
		return x;
	}
	fa[x] = find(fa[x]);
	return find(fa[x]);
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int l = j+1; l <= n; l++)
			{
				m++;
				e[m].u = j;
				e[m].v = l;
				e[m].w = c[i][j] + c[i][l];
			}
		}
	}
	sort(e+1, e+m+1, cmp);
	int cnt = 0, y = 1;
	while(cnt < n-1 && y <= m)
	{
		while(find(e[y].u) == find(e[y].v))
		{
			y++;
		}
		cnt++;
		ans += e[y].w;
		fa[find(e[y].u)] = find(e[y].v);
		y++;
	}
	cout << ans << endl;
	return 0;
}
