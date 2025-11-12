#include <bits/stdc++.h>
using namespace std;
struct P{
	int v,w;
};
vector<P>e[10004];
int u,v,w;int n,m,k,sum;
int c[10004],a[10004][10005];
int dis[10004];
bool vis[10004];
void dfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	vis[s] = 1;
	for (int j = 2;j <= n;j++)
	{
		if (!vis[j])continue;
		for (int i = 0;i < e[j].size();i++)
		{
			int v = e[j][i].v;
			int w = e[j][i].w;
			if (dis[v] > dis[u]+w)
			{
				dis[v] = dis[u] + w;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		e[u].push_back((P){v,w});
		e[v].push_back((P){u,w});
	}
	for (int i = 1;i <= n;i++)
	if (k == 0)
	{
		dfs(1);
		for (int i = 1;i <= m;i++)
		{
			for (int j = 0;j < e[i].size();j++)
			{
				sum+=e[i][j].w;
			}
		}
		cout << sum/4-1 << endl;
		return 0;
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (int j = i;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4*/
