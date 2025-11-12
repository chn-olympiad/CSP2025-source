#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
struct node
{
	int v,w;
};
int n,m,k,c[10005],a[100005],dis[100005],vis[100005],f[10005][10005],ans;
vector<node > g[100005];
priority_queue<pii > q;
void bfs()
{
	while(q.size())
	{
		int t=q.top().second;
		q.pop();
		if(vis[t]) return ;
		vis[t]=1;
		for(int i=0;i<g[t].size();i++)
		{
			int val=g[t][i].w,u=g[t][i].v;
			if(vis[u]) continue;
			if(dis[u]>dis[t]+val)
			{
				dis[u]=dis[t]+val;
				f[u][t]=dis[u];f[t][u]=dis[u];
				q.push({-dis[u],u});
			}
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
			dis[i]=0x3f3f3f3f;
		dis[1]=0;
		q.push({-dis[1],1});
		bfs();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			ans+=f[i][j];
	}
	cout<<ans;
	return 0;
}
