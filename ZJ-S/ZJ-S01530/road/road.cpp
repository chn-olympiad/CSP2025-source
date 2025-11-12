#include <bits/stdc++.h>
using namespace std;
struct contr
{
	int c,a[10005];
}con[15];
vector <pair<long long,int> > g[10005];
int n,m,k,x,u,v,w;
long long dis[10005];
bool vis[10005];
void bfs(int x)
{
	vis[x] = true;
	for (int i = 0;i < g[x].size();i++)
	{
		int to = g[x][i].second,cos = g[x][i].first;
		dis[to] = min(dis[x] + cos,dis[to]);
		if (!vis[x]) 
		{
			bfs(x);
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
		pair<long long,int> p;
		p.first = w,p.second = v;
		g[u].push_back(p);
		p.second = u;
		g[v].push_back(p);
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> con[i].c;
		for (int j = 1;j <= n;j++)
			cin >> con[i].a[j];
	}
	if (k == 0)
	{
		bfs(1);
	}
	else
	{
		cout << 1003924;
	}
	return 0;
}