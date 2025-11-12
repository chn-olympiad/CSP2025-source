#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
	int length,pt1,pt2;
};
int n,m,k,u,v,w;
long long ans;
edge e[2000005];
int gp[10005],c[15],a[15][10005];
int dfn(int x)
{
	gp[x]=(gp[x]==x?x:dfn(gp[x]));
	return gp[x];
}
bool cmp(edge x,edge y)
{
	return x.length<y.length;
}
signed main()
{
	//freopen("road.in","w",stdin);
	//freopen("road.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[i]=edge{w,u,v};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int p=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j])
			{
				p=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j==p)
			{
				continue;
			}
			e[++m]=egde{a[i][j],j,p};
		}
	}
	for(int i=1;i<=n;i++)
	{
		gp[i]=i;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(dfn(e[i].pt1)==dfn(e[i].pt2))
		{
			continue;
		}
		ans+=e[i].length;
		gp[e[i].pt1]=dfn(gp[e[i].pt2]);
	}
	cout<<ans<<endl;
	return 0;
}
