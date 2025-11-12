#include<bits/stdc++.h>
using namespace std;
long long int l[1000][1000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	long long int u,v,w,cj,a,ans,minn=1e18;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		l[u][v]=w;
		l[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cj;
		for(int j=1;j<=n;j++)
		cin>>a;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j<=n;j++)
		{
			if(l[i][j]!=0)
			minn=min(minn,l[i][j]);
		}
		ans+=minn;
		minn=1e18;
	}
	cout<<ans;
	return 0;
 } 
