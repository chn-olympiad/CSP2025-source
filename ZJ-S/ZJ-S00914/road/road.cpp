#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e6+10;
struct edge
{
	int u,v,w;
}e[M];
int c[15],vis[15],fa[N];
long long ans=1e18;
int n,m,k;
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void init()
{
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
}
void dfs(int x,int sum)
{
	if(x==k+1)
	{
		long long res=sum;
		init();
		for(int i=1;i<=m+k*n;i++)
		{
			if(e[i].u>n)
			{
				if(!vis[e[i].u-n])
				{
					continue;
				}
			}
			int x=find(e[i].u);
			int y=find(e[i].v);
			if(x!=y)
			{
				fa[x]=y;
				res+=e[i].w;
			}
		}
		ans=min(ans,res);
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+c[x]);
	vis[x]=0;
	dfs(x+1,sum);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);	
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&e[m+(i-1)*n+j].w);
			e[m+(i-1)*n+j].u=n+i,e[m+(i-1)*n+j].v=j;
		}
	}
	sort(e+1,e+1+m+k*n,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}

