#include<bits/stdc++.h>
using namespace std;
struct point
{
	int e, w;
};
struct point2
{
	int x, y, z;
};
map<pair<int, int>, int> mp;
int n, m, k, va[105], t;
vector<point> g[20005];
point2 g2[1000005];
int fa[10005];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(point2 x, point2 y)
{
	return x.z < y.z;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &g2[i].x, &g2[i].y, &g2[i].z);
		if(mp[{g2[i].x, g2[i].y}] == 1 || mp[{g2[i].y, g2[i].x}] == 1) continue;
		mp[{g2[i].x, g2[i].y}] = 1;
		g[g2[i].x].push_back({g2[i].y, g2[i].z});
		g[g2[i].y].push_back({g2[i].x, g2[i].z});
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &va[i]);
		if(va[i] != 0) t = 1;
		for(int j = 1; j <= n; j++)
		{
			int x;
			scanf("%d", &x);
			if(x != 0) t = 1;
			g[j].push_back({n + i, x});
			g[n + i].push_back({j, x});
		}
	}
	if(t == 0 && k != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(k == 0)
	{
		int ans = 0;
		sort(g2 + 1, g2 + m + 1, cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++)
		{
			if(find(g2[i].x) != find(g2[i].y))
			{
				fa[find(g2[i].x)] = find(g2[i].y);
				ans += g2[i].z;
			}
		}
		cout << ans << endl;
		return 0;
	}
    return 0;
}
