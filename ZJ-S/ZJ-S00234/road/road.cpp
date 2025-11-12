#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int v,w;
}f[10005][17];
struct node{
	int u,v,w;
}e[1000005];
inline bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,m,k,cnt,fa[10005],sum,b[17][10005];
vector<edge>g[10005];
inline int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]); 
}
void dfs(int u,int fath)
{
	for(int i=0;i<g[u].size();i++)
		if(g[u][i].v!=fath)
		{
			f[g[u][i].v][0]={u,g[u][i].w};
			sum+=g[u][i].w;
			dfs(g[u][i].v,u);
		}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m&&cnt<=n-1;i++)
	{
		int x=find(e[i].u);
		int y=find(e[i].v);
//		cout<<i<<endl;
		if(x!=y)
		{
			cnt++;
			fa[x]=y;
			sum+=e[i].w;
//			g[e[i].u].push_back({e[i].v,e[i].w});
//			g[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
//	f[1][0].v=1;
//	dfs(1,1);
	cout<<sum;
//	for(int j=1;j<=14;j++)
//		for(int i=1;i<=n;i++)
//		{
//			f[i][j].v=f[f[i][j-1].v][j-1];
//			f[i][j].w=max(f[i][j-1].w,f[f[i][j-1].v][j-1].w);
//		}
//	for(int i=1;i<=k;i++)
//	{
//		scanf("%lld",&b[i][0]);
//		if(b[i][0]==0)
//		{
//			int jd,kk;
//			for(int j=1;j<=n;j++)
//			{
//				scanf("%lld",&b[i][j]);
//				if(b[i][j]==0)
//					jd=j;
//			}
//			for(int i=1;i<=n;i++)
//				if(jd)
//					kk=lca(jd,i);
//		}
//		
//	}
	return 0;
}
