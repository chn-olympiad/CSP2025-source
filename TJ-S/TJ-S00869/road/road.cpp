#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int u, v;
	long long w;
};
node g[2000010];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int f[10010];
long long a[10010], c[15];
int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y)
{
	f[find(x)] = find(y);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int u1, v1;
		long long w1;
		cin >> u1 >> v1 >> w1;
		cnt++;
		g[cnt] = (node){u1, v1, w1};
	}
	for (int j = 1; j < n; j++)
	{
		for (int k = j + 1; k <= n; k++)
		{
			cnt++;
			g[cnt].u = j;
			g[cnt].v = k;
			g[cnt].w = 1e9;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		cnt = m;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		for (int j = 1; j < n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				cnt++;
				g[cnt].w = min(g[cnt].w, a[j] + a[k] + c[i]);
			}
		}
	}
	sort(g + 1, g + cnt + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	long long ans = 0;
	int cur = 0;
	for (int i = 1; i <= cnt; i++)
	{
		int x = g[i].u;
		int y = g[i].v;
		if (find(x) != find(y))
		{
			merge(x, y);
			ans += g[i].w;
			cur++;
		}
		if (cur == n - 1) break;
	}
	cout << ans;
	return 0;
}
