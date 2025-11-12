#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+5;
const int maxm=1e6+5;
const int maxk=15;

int n,m,k;
int c[maxk],a[maxk][maxn];

//int g[maxk][]

struct edge
{
	int u,v,w;
}e[maxm];
//int cnt;
//int head[maxn];

//void add(int u,int v,int w)
//{
//	e[++cnt].to=v;
//	e[cnt].nex=head[u];
//	head[u]=cnt;
//}

int fa[maxn];
int g[maxk][maxn];

int get(int x)
{
//	if(fa[x]==x)
//	{
//		return x;
//	}
	return (fa[x]==x)?x:(fa[x]=get(fa[x]));
}

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

bool vis[maxk][maxn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
//		int u,v,w;
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
//		add(u,v,w);
//		add(v,u,w);
	}
	bool flag=true;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=0)
		{
			flag=false;
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				flag=false;
			}
		}
	}
	if(flag)
	{
		puts("0");
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		for(int j=1;j<=k;j++)
		{
			g[j][i]=a[j][i];
		}
	}
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int a=e[i].u,b=e[i].v;
			a=get(a);
			b=get(b);
			if(a==b)
			{
				continue;
			}
			else
			{
				fa[a]=b;
//				for(int i=1;i<=k;i++)
//				{
//					g[a]=min(g[i][a],g[i][b]);
//				}
				ans+=e[i].w;
			}
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int a=e[i].u,b=e[i].v;
			a=get(a);
			b=get(b);
			if(a==b)
			{
				continue;
			}
			else
			{	
				int w=e[i].w;
				int h=0;
				for(int i=1;i<=k;i++)
				{
					int tem=0;
					if(vis[a])
					{
						tem=g[i][b];
					}
					if(vis[b])
					{
						tem=g[i][a];
					}
					tem=g[i][a]+g[i][b]+c[i];
					if(tem<w)
					{
						w=tem;
						h=i;
					}
//					w=min(w,g[i][a]+g[i][b])
					g[i][b]=min(g[i][a],g[i][b]);
//					w=min(w,)
				}
				fa[a]=b;
				vis[h][b]=1;
				ans+=w;
			}
		}
	} 
	printf("%lld\n",ans);
//	for 
	return 0;
}
/*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4 
 100 1 3 2 4
*/

