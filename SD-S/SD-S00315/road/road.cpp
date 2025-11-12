#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct Edge
{
	int v, w;
};
struct Node
{
	int id, dis;
	bool operator<(const Node &b) const
	{
		return dis > b.dis;
	}
};
int n, m, k, u, v, w, c[15], a[15][10005], nowsz[10015], sz[10015], dis[10015];
long long nans, fnans = 0x3f3f3f3f3f3f3f3f;
vector <Edge> g[10015];
priority_queue <Node> q;
bool vis[10015];
long long prim()
{
	long long ret = 0;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push((Node){1, dis[1] = 0});
	while (q.size())
	{
		int u = q.top().id;
		q.pop();
		if (vis[u])
		{
			continue;
		}
		vis[u] = 1;
		ret += dis[u];
		for (int i = 0;i < nowsz[u];i++)
		{
			++times;
			int v = g[u][i].v;
			long long w = g[u][i].w;
			if (dis[v] > w)
			{
				q.push((Node){v, dis[v] = w});
			}
		}
	}
	return ret;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back((Edge){v, w});
		sz[u]++;
		g[v].emplace_back((Edge){u, w});
		sz[v]++;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k;j++)
		{
			g[i].emplace_back((Edge){0, 0});
		}
	}
	for (int i = 1;i <= k;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			g[n + i].emplace_back((Edge){0, 0});
		}
	}
	for (int i = 1;i <= k;i++)
	{
		scanf("%d ", &c[i]);
		for (int j = 1;j <= n;j++)
		{
			scanf("%d ", &a[i][j]);
		}
	}
	for (int i = 0;i < (1 << k);i++)
	{
		nans = 0;
		for (int j = 1;j <= n + k;j++)
		{
			nowsz[j] = sz[j];
		}
		for (int j = 0;j < k;j++)
		{
			if (i & (1 << j))
			{
				nans += c[j + 1];
				for (int l = 1;l <= n;l++)
				{
					g[l][nowsz[l]++] = (Edge){n + j + 1, a[j + 1][l]};
					g[n + j + 1][nowsz[n + j + 1]++] = (Edge){l, a[j + 1][l]};
				}
			}
		}
		fnans = min(fnans, nans + prim());
	}
	printf("%lld", fnans);
	return 0;
}
