#include<bits/stdc++.h>
#define int long long
using namespace std;
int ret=(int)1e18;
int n,m,k;
int fa[10020];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node
{
	int u,v,w;
	node(){}
	node(int U,int V,int W)
	{
		u=U;
		v=V;
		w=W;
	}
}ed[1000010],ed1[1110010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int c[20],a[20][10010];
int mk[20];
void dfs(int now)
{
	if(now==k+1)
	{
		int E=m;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int ans=0;
		int ww=0;
		for(int i=1;i<=m;i++)ed1[i]=ed[i];
		for(int i=1;i<=k;i++)if(mk[i]==1)
		{
			ww++;
			ans+=c[i];
			for(int j=1;j<=n;j++)
			{
				ed1[++E]=node(j,i+n,a[i][j]);
			}
		}
		sort(ed1+1,ed1+E+1,cmp);
		int k=0;
		for(int i=1;i<=E;i++)
		{
			if(k>=n+ww-1)break;
			if(ans>ret)return;
			int v1=find(ed1[i].u);
			int v2=find(ed1[i].v);
			if(v1!=v2)
			{
				k++;
				ans+=ed1[i].w;
				fa[v1]=v2;
			}
		}
		ret=min(ans,ret);
		return;
	}
	mk[now]=1;
	dfs(now+1);
	mk[now]=0;
	dfs(now+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&ed[i].u,&ed[i].v,&ed[i].w);
	}
	if(k==0)
	{
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int ans=0;
		sort(ed+1,ed+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int v1=find(ed[i].u);
			int v2=find(ed[i].v);
			if(v1!=v2)
			{
				ans+=ed[i].w;
				fa[v1]=v2;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]!=0)flag=1;
		}
	}
	if(flag==0)
	{
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ret);
	return 0;
}
