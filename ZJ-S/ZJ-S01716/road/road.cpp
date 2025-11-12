#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int u;
	int v;
	int w;
};
int ans = 0, n, m, k, c[15], edge[15][10005], pa[20005], s[20005], flag = 0;
node a[2000005];
int find(int a)
{
	if (pa[a] == a)
		return a;
	return pa[a] = find(pa[a]);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (s[x] > s[y])
		swap(x, y);
	s[y] += s[x];
	pa[x] = y;
	return;
}
bool cmp(node x, node y){ return x.w < y.w; }
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> edge[i][j];
	}
	for (int i = 1; i <= k; i++)
	{
		if (c[i] != 0)
		{
			flag++;
			break;
		}
	}
	if (k == 0)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			pa[i] = i;
		for (int i = 1; i <= n; i++)
			s[i] = 1;
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			if (cnt == n - 1)
				break;
			if (find(a[i].u) == find(a[i].v))
				continue;
			cnt++;
			ans += a[i].w;
			unite(a[i].u, a[i].v);
		}
		cout << ans;
		return 0;
	}
	if (flag == 0)
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				m++;
				a[m].u = j;
				a[m].v = n + i;
				a[m].w = edge[i][j];
			}
		}
		n += k;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			pa[i] = i;
		for (int i = 1; i <= n; i++)
			s[i] = 1;
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			if (cnt == n - 1)
				break;
			if (find(a[i].u) == find(a[i].v))
				continue;
			cnt++;
			ans += a[i].w;
			unite(a[i].u, a[i].v);
		}
		cout << ans;
		return 0;
	}
	return 0;
}