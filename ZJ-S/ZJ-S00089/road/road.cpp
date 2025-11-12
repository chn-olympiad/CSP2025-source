#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int c[15],a[15][10005];
bool vis[15];
int minn=1e14;
int ans=0;
int fa[10050];
struct node
{
	int u,v,w;
}e[2000005],eg[2000005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void min_make_tree(int p)
{
	sort(eg+1,eg+p,cmp);
	for(int i=1;i<=n+20;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<p;i++)
	{
//		printf("%lld %lld %lld\n",find(eg[i].u),find(eg[i].v),eg[i].w);
		if(find(eg[i].v)!=find(eg[i].u))
		{
			fa[find(eg[i].v)]=eg[i].u;
			ans+=eg[i].w;
		}
		if(ans>=minn)
			return ;
	}
	minn=min(minn,ans);
}
void dfs(int w)
{
	if(w==k+1)
	{
		ans=0;
		int p=m+1;
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==1)
			{
				ans+=c[i];
				for(int j=1;j<=n;j++)
				{
					e[p].u=n+i,e[p].v=j,e[p].w=a[i][j];
					p++;
				}
			}
		}
		for(int i=1;i<p;i++)
		{
			eg[i]=e[i];
		}
		min_make_tree(p);
		return ;
	}
	vis[w]=1;
	dfs(w+1);
	vis[w]=0;
	dfs(w+1);
}
bool check()
{
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0)
			flag=1;
		bool flag1=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
				flag1=1;
		}
		if(flag1==0)
			flag=1;
	}
	if(flag==1)
		return 0;
	int p=m+1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				for(int k=1;k<=n;k++)
				{
					if(k!=j)
					{
						e[p].u=j,e[p].v=k,e[p].w=a[i][k];
						p++;
					}
				}
			}
		}
	}
	for(int i=1;i<p;i++)
	{
		eg[i]=e[i];
	}
	min_make_tree(p);
	printf("%lld\n",minn);
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
    	scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	if(check()==1)
		return 0;
	dfs(1);
	printf("%lld\n",minn);
}
