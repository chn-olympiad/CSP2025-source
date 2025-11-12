//freopen("road.in","r",stdin);
//freopen("road.out","w",stdout);
#include<bits/stdc++.h>
using namespace std;
struct road
{
	long long u,v,w;
};
road G[1000005];
long long c[15];
long long a[15][10005];
long long U[10005];
long long n,m,k;
long long ans;
bool cmp(road x,road y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		G[i]={u,v,w};
	}
	for(long long j=1;j<=k;j++)
	{
		cin>>c[j];
		for(long long i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	sort(G+1,G+m+1,cmp);
	for(long long i=1;i<=n;i++)	U[i]=i;
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		u=G[i].u;
		v=G[i].v;
		w=G[i].w;
		if(U[u]!=U[v])
		{
			ans=ans+w;
			U[v]=U[u];
		}
	}
	cout<<ans;
}
