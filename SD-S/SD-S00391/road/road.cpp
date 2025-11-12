#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15],a[15][10005],b[10010];
bool vis[15];
long long ans=0;
struct road{
	int u,v,w;
};
bool cmp(road a,road b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(b[x]==x)
	{
		return x;
	}
	else
	{
		return b[x]=find(b[x]);
	}
}
road r[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(b[r[i].u]==b[r[i].v])
		{
			continue;
		}
		else
		{
			ans+=r[i].w;
			b[find(r[i].u)]=find(r[i].v);
			find(r[i].u);
		}
	}
	cout<<ans;
	return 0;
}

