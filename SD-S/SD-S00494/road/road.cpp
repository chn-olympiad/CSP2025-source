#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k,ans,cnt,fa[10010],f[10010][10010];
long long a[10][10010];
struct node
{
	long long w,u,v;
}e[1000010];
int find(int x)
{
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		if (e[i].u>e[i].v) swap(e[i].u,e[i].v);
		f[e[i].u][e[i].v]=i;
	}
	if (k)
	{
		for (int i=1;i<=k;i++)
		{
			int c;
			scanf("%d",&c);
			for (int j=1;j<=n;j++)
			{
				a[i][j]=read();
			}
		}
		for (int h=1;h<=k;h++)
		{
			for (int i=1;i<n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					if (f[i][j])
					{
						e[f[i][j]].w=min(e[f[i][j]].w,a[h][i]+a[h][j]);
					}
					else
					{
						e[++m].u=i;
						e[m].v=j,e[m].w=a[h][i]+a[h][j];
						f[i][j]=m;
					}
				}
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (cnt==n-1) break;
		int u=e[i].u,v=e[i].v,uu=find(u),vv=find(v);
		if (uu==vv) continue;
		cnt++;
		fa[uu]=fa[v];
		ans+=e[i].w;
	}
	cout<<ans;
	return 0;
}
