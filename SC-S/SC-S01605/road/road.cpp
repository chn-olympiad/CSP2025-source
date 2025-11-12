#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace	std;
const int N = 1e6 + 10;
int head[N], tot, dis[N], vis[N];
struct Edge
{
	int next, to, w;
}edge[N * 4];
void add_Edge(int u, int v, int w)
{
	edge[++ tot] = {head[u], v};
	head[u] = tot;
}
void dijkstra(int s)
{
	memset(dis, __INT_MAX__, sizeof(dis));
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
	pq.push({0, s});
	vis[s] = 1;
	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (!vis[u])
		{
			for (int i = head[u]; ~i; i = edge[i].next)
			{
				int v = edge[i].to, w = edge[i].w;
				if (dis[u] + w < dis[v])
				{
					dis[v] = dis[u] + w;
					pq.push({dis[v], v});
				}
			}
		}
	}
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	memset(head, -1, sizeof(head));
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	for (int i = 0; i < m; i ++)
	{
		int u, v, w;
		add_Edge(u, v, w);
		add_Edge(v, u, w);
	}
	for (int i = 0; i < n; i ++)
	{
		add_Edge(0, n, 0);
	}
	dijkstra(0);
	int mn = __INT_MAX__;
	for (int i = 0; i < n; i ++)
	{
		mn = min(mn, dis[i]);
	}
	cout << mn << endl;
	return 0;
}