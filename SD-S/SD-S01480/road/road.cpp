#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10050],c[15];
struct Edge
{
	int u,v,w;
}a[1000010],b[15][10010];
vector<Edge> e;
bool flag;
long long ans=1e18,res;
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void f()
{
	for(int i=1;i<=n+k;i++)	fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(auto &i:e)
	{
		int x=Find(i.u),y=Find(i.v);
		if(x!=y)
		{
			fa[x]=y;
			res+=i.w;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)	scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i])	flag=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j].w);
			b[i][j].u=j;
			b[i][j].v=n+i;
		}
	}
	if(flag==0)
	{
		for(int i=1;i<=m;i++)	e.push_back(a[i]);
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)	e.push_back(b[i][j]);
		}
		f();
		printf("%lld",res);
		return 0;
	}
	for(int i=0;i<(1<<k);i++)
	{
		e.clear();
		res=0;
		for(int i=1;i<=m;i++)	e.push_back(a[i]);
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				res+=c[j];
				for(int p=1;p<=n;p++)		e.push_back(b[j][p]);
			}
		}
		f();
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}

