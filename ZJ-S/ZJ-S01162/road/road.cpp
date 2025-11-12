#include<bits/stdc++.h>
using namespace std;
int n,m,k,idx;
int f[100020],a[20][30020],lg[100020],c[20];
void init()
{
	for(int i=1;i<=n*2+k;i++)
	f[i]=i;
	return;
}
int find(int x)
{
	if(f[x]!=x)
	{
		f[x]=find(f[x]);
	}
	return f[x];
}
bool merge(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v)
	{
		return false;
	}
	f[u]=v;
	return true;
}
struct node
{
	int u,v,w;
};
node ex[1000020],e[30020],g[1050][20020];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long kruscal1()
{
	sort(ex+1,ex+m+1,cmp);
	init();
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(merge(ex[i].u,ex[i].v))
		{
			ans+=ex[i].w;
			idx++;
			g[0][idx].u=ex[i].u;
			g[0][idx].v=ex[i].v;
			g[0][idx].w=ex[i].w;
		}
	}
	return ans;
}
long long kruscal(int cnt)
{
	sort(e+1,e+cnt+1,cmp);
	init();
	long long ans=0;
	idx=0;
	for(int i=1;i<=cnt;i++)
	{
		if(merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			idx++;
			ex[idx].u=e[i].u;
			ex[idx].v=e[i].v;
			ex[idx].w=e[i].w;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<=10;i++)
	lg[(1<<i)]=i;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&ex[i].u);
		scanf("%d",&ex[i].v);
		scanf("%d",&ex[i].w);
	}
	long long ans=kruscal1();
	g[0][0].w=idx;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int id,s;
	long long cnt=0;
	for(int i=1;i<(1<<k);i++)
	{
		cnt=0;
		id=lg[i&(-i)]+1;
		s=i^(i&(-i));
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				cnt+=c[j+1];
			}
		}
		for(int j=1;j<=g[s][0].w;j++)
		{
			e[j].u=g[s][j].u;
			e[j].v=g[s][j].v;
			e[j].w=g[s][j].w;
		}
		for(int j=1;j<=n;j++)
		{
			e[j+g[s][0].w].u=j;
			e[j+g[s][0].w].v=id+n;
			e[j+g[s][0].w].w=a[id][j];
		}
		cnt+=kruscal(n+g[s][0].w);
		g[i][0].w=idx;
		for(int j=1;j<=idx;j++)
		{
			g[i][j].u=ex[j].u;
			g[i][j].v=ex[j].v;
			g[i][j].w=ex[j].w;
		}
		ans=min(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
