#include <bits/stdc++.h>
using namespace std;
// Jiu Jiu Wo awa Kruskal
struct node
{
	int u, v, w;
};
bool cmp (node a, node b)
{
	return a.w < b.w;
}

const int N = 1e4 + 10;

int fa[N], siz[N];
vector <node> g;

int find(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		siz[i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node tmp;
		tmp.u = u;
		tmp.v = v;
		tmp.w = w;
		g.push_back(tmp);
	}
	sort(g.begin(), g.end(), cmp);
	int ans = 0, cnt = 0;
	for (int i = 0; i < g.size(); i++)
	{
		int x = find(g[i].u);
		int y = find(g[i].v);
		if (x == y)
		{
			continue;
		}
		if (siz[y] < siz[x])
		{
			swap(x, y);
		}
		if (siz[x] == siz[y])
		{
			siz[y] = siz[x] + 1;
		}
		fa[x] = y;
		ans += g[i].w;
		cnt++;
		if (cnt == n - 1)
		{
			cout << ans << "\n";
			return 0;
		}
	}
	return 0;
}
