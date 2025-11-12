#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=1e4+9,K=1e1+9;
LL n,m,k,u,v,w,city[N][N],c[K],a[K][N],Min=1e18,countryside,vis[K][N],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	while(m--)
	{
		cin>>u>>v>>w;
		city[u][v]=w;
		city[v][u]=w;
	}
	for(LL i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]<Min)
		{
			countryside=i;
		}
		for(LL j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(LL i=1;i<=n;i++)
	{
		for(LL j=i+1;j<=n;j++)
		{
			if(!vis[countryside][i]&&!vis[countryside][j])
			{
				if(city[i][j]<c[countryside]+a[countryside][i]+a[countryside][j]) ans+=city[i][j];
				else
				{
					vis[countryside][i]=vis[countryside][j]=1;
					ans+=c[countryside]+a[countryside][i]+a[countryside][j];
				}
			}
			else if(!vis[countryside][i]&&vis[countryside][j])
			{
				if(city[i][j]<c[countryside]+a[countryside][i]+a[countryside][j]) ans+=city[i][j];
				else
				{
					vis[countryside][i]=1;
					ans+=c[countryside]+a[countryside][i];
				}
			}
			else
			{
				if(city[i][j]<c[countryside]+a[countryside][i]+a[countryside][j]) ans+=city[i][j];
				else
				{
					vis[countryside][j]=1;
					ans+=c[countryside]+a[countryside][j];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}