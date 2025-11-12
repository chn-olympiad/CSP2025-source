#include<bits/stdc++.h>
#define int long long
using namespace std;
struct town
{
	int cost;  //cost == 0代表村庄已经城市化
	signed edge[10005];
}t[15];
struct graph
{
	int town; //要城市化哪个村庄 
	int distance; //距离(可经过村庄)
}d[10005];
bool vis[10005];
signed G[10005][10005];
int n, m, k;
int prim()
{
	d[0].distance = 1e9;
	d[1].distance = 0; vis[1] = true;
	for (int i = 2; i <= n; i++)
	{
		d[i].distance = G[1][i];
		for (int j = 1; j <= k; j++)
		{
			if (t[j].edge[1] + t[j].edge[i] + t[j].cost < d[i].distance)
			{
				d[i].distance = t[j].edge[1] + t[j].edge[i] + t[j].cost;
				d[i].town = j;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int mi = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				continue;
			}
			if (d[i].distance < d[mi].distance)
			{
				mi = i;
			}
		}
		vis[mi] = true;
		t[d[mi].town].cost = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				continue;
			}
			if (d[i].distance > G[mi][i])
			{
				d[i].distance = G[mi][i];
				d[i].town = 0;
			}
			for (int j = 1; j <= k; j++)
			{
				if (t[j].edge[mi] + t[j].edge[i] + t[j].cost < d[i].distance)
				{
					d[i].distance = t[j].edge[mi] + t[j].edge[i] + t[j].cost;
					d[i].town = j;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += d[i].distance;
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(G, 0x3f, sizeof G);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> t[i].cost;
		for (int j = 1; j <= n; j++)
		{
			cin >> t[i].edge[j];
		}
	}
	cout << prim() << endl;
	return 0;
}