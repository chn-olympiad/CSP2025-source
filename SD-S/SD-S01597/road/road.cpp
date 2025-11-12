#include<bits/stdc++.h>
using namespace std;
#define int long long  
int const N=1e4+15,M=13e5+5;
int n,m,k,fa[N],c[15],a[15][N],ans,cnte,cntm,cntd,mw;
struct edge
{
	int u,v,w;
	bool operator < (const edge &x)
	{
		return w<x.w;
	}
}e[M],ee[15][N],ne[M],tmp[M];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>ee[i][j].w,ee[i][j].u=i+n,ee[i][j].v=j;
		sort(ee[i]+1,ee[i]+n+1);
	}
	iota(fa+1,fa+n+1,1);
	cntm=n-1;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)
			continue;
		fa[u]=v;
		ans+=e[i].w;
		e[++cnte]=e[i];
		if(cnte==n-1)
			break;
	}
	mw=e[n-1].w;
	for(int sta=1;sta<(1<<k);sta++)
	{
		int an=0;
		cnte=cntm,cntd=n;
		for(int i=1;i<=cntm;i++)
			ne[i]=e[i];
		for(int j=0;j<k;j++)
		{
			if((sta>>j)&1^1)
				continue;
			an+=c[j+1],cntd++;
			if(an>=ans)
				break;
			int x=1,y=1,kk=1;
			while(x<=cnte&&y<=n&&ee[j+1][y].w<mw)
			{
				if(ne[x].w<ee[j+1][y].w)
					tmp[kk++]=ne[x++];
				else
					tmp[kk++]=ee[j+1][y++];
			}
			while(x<=cnte)
			{
				tmp[kk++]=ne[x++];
			}
			while(ee[j+1][y].w<mw&&y<=n)
			{
				tmp[kk++]=ee[j+1][y++];
			}
			cnte=kk;
			for(int i=1;i<=kk;i++)
				ne[i]=tmp[i];
		}
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		int ct=0;
		for(int i=1;i<=cnte;i++)
		{
			int u=find(ne[i].u),v=find(ne[i].v);
			if(u==v)
				continue;
			an+=ne[i].w;
			fa[u]=v;
			ct++;
			if(an>=ans||ct==cntd-1)
				break;
		}
		ans=min(an,ans);
	}
	cout<<ans;
	return 0;
}
