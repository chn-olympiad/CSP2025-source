#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10011],c[11],a[11][10001],ans;
struct T
{
	int u,v,w;
}e[1110001];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	fa[find(y)]=find(x);
}
bool cmp(T x,T y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			if(find(e[i].u)==find(e[i].v))
				continue;
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[m+j+(i-1)*n].u=n+i;
			e[m+j+(i-1)*n].v=j;
			e[m+j+(i-1)*n].w=a[i][j];
		}
	}
	sort(e+1,e+m+n*k+1,cmp);
	for(int i=1;i<=m+n*k;i++)
	{
		if(find(e[i].u)==find(e[i].v))
			continue;
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
	}
	cout<<ans;
	return 0;
}
