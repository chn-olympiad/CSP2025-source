#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
int n,m,k,ans;
struct node{
	int v,w;
};
vector<node> g[MAXN];
int dis[MAXN];
bool vis[MAXN];
void Prim()
{
	for(int i = 1;i<=n;i++) dis[i] = 1e9;
	int now = 1;
	dis[now] = 0,vis[now] = 1;
	for(int i = 1;i<n;i++)
	{
		int minn = 1e9,min_id = -1;
		for(int j = 0;j<(int)g[now].size();j++)
		{
			if(!vis[g[now][j].v])
				dis[g[now][j].v] = min(dis[g[now][j].v],g[now][j].w);
		}
		for(int j = 2;j<=n;j++)
		{
			if(!vis[j] && minn > dis[j]) minn = min(minn,dis[j]),min_id = j;
		}
		ans += minn;
		now = min_id;
		vis[now] = 1;
		//cout << i << " " << minn << " " << now << '\n';
		//for(int i = 1;i<=n;i++) cout << dis[i] << " ";cout << '\n';
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back((node){v,w});
		g[v].push_back((node){u,w});
	}
	Prim();
	cout << ans;
    return 0;
}

