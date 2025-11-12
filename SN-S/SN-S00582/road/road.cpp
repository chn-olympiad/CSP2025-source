//Ãÿ ‚–‘÷  40pts 
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
#define ll long long
struct node{
	int u,v;
	ll w;
}g[1000006];
ll d[15][1005];
ll c[15];
ll dis[1005][1005];
int fa[1005];
int find(int k)
{
	if(k==fa[k]) return k;
	return fa[k]=find(fa[k]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int tot;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int u,v;ll w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=dis[u][v];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&d[i][j]);
	}
	for(int t=1;t<=k;t++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],d[t][i]+d[t][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		for(int j=i+1;j<=n;j++)
		{
			g[++cnt]={i,j,dis[i][j]};
		}
	}
	sort(g+1,g+cnt+1,cmp);
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(g[i].u)!=find(g[i].v))
		{
			ans+=g[i].w;
			fa[find(g[i].u)]=find(g[i].v);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
