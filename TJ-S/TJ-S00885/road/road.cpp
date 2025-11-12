#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n, m, k;
long long sum = 0;
vector <pair <int, int> > adj[10005];
struct node
{
	int val, r[10005];
} town[15];
vector <int> sides[10005];
inline void prim()
{
	priority_queue <pair <pair <int, int>, pair <int, int> > > q;
	q.push({{0, 0}, {0, 1}});
	int c = 0;
	bool vis[10005] = {};
	while (c < n)
	{
		int side = q.top().first.first, sideid = q.top().first.second, u = q.top().second.first, v = q.top().second.second;
		q.pop();
		sides[u].push_back(sideid);
		sum -= side;
		vis[v] = 1;
		c++;
		for (int i = 0; i < adj[v].size(); i++)
		{
			int vv = adj[v][i].first, w = adj[v][i].second;
			if (!vis[vv])
			{
				q.push({{-w, i}, {v, vv}});
			}
		}
	}
}
inline void x(int u, int v)
{
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i].first == v)
		{
			sides[u].push_back(v);
			return ;
		}
	}
}
inline int route(int s, int e)
{
	queue <pair <int, int> > q;
	q.push({s, 0});
	bool vis[10005] = {};
	while (!q.empty())
	{
		int u = q.front().first, maxn = q.front().second;
		q.pop();
		if (u == e)
		{
			return maxn;
		}
		vis[u] = 1;
		for (int i = 0; i < sides[u].size(); i++)
		{
			int v = adj[u][sides[u][i]].first, w = adj[u][sides[u][i]].second;
			if (!vis[v])
			{
				q.push({v, max(maxn, w)});
			}
		}
	}
}
inline void link()
{
	for (int u = 1; u <= n; u++)
	{
		for (int v = u+1; v <= n; v++)
		{
			long long minn = 9e18;
			int minp;
			for (int i = 1; i <= k; i++)
			{
				if (minn > town[i].val+town[i].r[u]+town[i].r[v])
				{
					minn = town[i].val+town[i].r[u]+town[i].r[v];
					minp = i;
				}
			}
			int ori = route(u, v);
			if (ori > minn)
			{
				sum -= ori;
				sum += minn;
				town[minp].val = 0;
				town[minp].r[u] = 0;
				town[minp].r[v] = 0;
			}
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> town[i].val;
		for (int j = 1; j <= n; j++)
		{
			cin >> town[i].r[j];
		}
	}
	prim();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < sides[i].size(); j++)
		{
			x(sides[i][j], i);
		}
	}
	link();
	cout << sum;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
