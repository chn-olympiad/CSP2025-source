#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int flag[N];
int dis[N];
vector<int>G[N];
int d[N][N];
int n,m,k;
int ansn = -1;
void dijkstra(int s)
{
	ansn = -1;
	for(int i = 1;i<=n;i++)
	{
		dis[i] = -1;
	}
	dis[s]=0;
	flag[s]=1;
	memset(flag,0,sizeof flag);
	for(int i = 1;i<=n;i++)
	{
		int maxn = -1;
		int u = 0;
		for(int j = 1;j<=n;j++)
		{
			if(maxn<dis[j]&&flag[j]==0)
			{
				maxn=dis[j];
				u=j;
			}
		}
		ansn = max(ansn,dis[u]);
		flag[u]=1;
		for(auto v : G[u])
		{
			if(dis[u]+d[u][v]>dis[v])
			{
				dis[v] = dis[u]+d[u][v];
			}
		}
	}
}
void solve1()
{
	for(int i = 1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		d[u][v]=d[v][u]=w;
	}
	int ans = -0x3f3f3f3f;
	for(int i = 1;i<=n;i++)
	{
		dijkstra(i);
//		printf("i = %d,ansn = %d\n",i,ansn);
		ans=max(ans,ansn);
	}
	cout<<ans<<"\n";
}
void solve2()
{
	for(int i = 1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		d[u][v]=d[v][u]=w;
	}
	int ans = -0x3f3f3f;
	for(int i = 1;i<=k;i++)
	{
		int ct;
		cin>>ct;
		for(int j = 1;j<=n;j++)
		{
			int w;
			cin>>w;
			int u = n+i;
			int v = j;
			G[u].push_back(v);
			G[v].push_back(u);
			d[u][v]=d[v][u]=w;
		}
	}
	for(int i = 1;i<=n+k;i++)
	{
		dijkstra(i);
		ans=min(ans,ansn);
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)solve1();
	else solve2();
	return 0;
}
