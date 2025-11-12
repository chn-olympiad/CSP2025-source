#include<bits/stdc++.h>
using namespace std;
#define int long long
struct d
{
	int v,w;
};
int n,m,k,ans=1e18,u,v,w,c[15][10005];
vector <d> g1[10005],g[10105];
int dis[10105],vis[10105],ch[15];
int kru()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n+k;i++) g[i].clear();
	int cho=0,sum=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<g1[i].size();j++)
			g[i].push_back(g1[i][j]);
	for(int i=1;i<=k;i++)
		if(ch[i])
		{
			cho++;
			sum+=c[i][0];
			for(int j=1;j<=n;j++)
			{
				g[n+cho].push_back({j,c[i][j]});
				g[j].push_back({n+cho,c[i][j]});
			}
		}
	for(int i=0;i<=n+cho;i++) dis[i]=1e18;
	vis[1]=1,dis[1]=0;
	for(int i=0;i<g[1].size();i++)
		dis[g[1][i].v]=g[1][i].w;
	int num;
	for(int i=1;i<n+cho;i++)
	{
		num=0;
		for(int j=1;j<=n+cho;j++)
			if(!vis[j]&&dis[num]>dis[j])
				num=j;
		vis[num]=1;sum+=dis[num];
		for(int j=0;j<g[num].size();j++)
			dis[g[num][j].v]=min(dis[g[num][j].v],g[num][j].w);
	}
	return sum;
}
void dfs(int x)
{
	if(x>k)
	{
		ans=min(ans,kru());
		return;
	}
	ch[x]=1;
	dfs(x+1);
	ch[x]=0;
	dfs(x+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road1.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		g1[u].push_back({v,w});
		g1[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&c[i][j]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
