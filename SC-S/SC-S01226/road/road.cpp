#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,ans=0,cnt=1,l=1;
long long a[11000][11000];
long long f[11000][11000];
long long g[11000];
long long c[20][11000];
void dfs(long long x,long long ans)
{
	g[x]=1;
	for (long long i=1;i<=n;i++)
	{
		if (f[x][i]==1 && a[x][i]>=0)
		{
			if (g[i]==0)
			{
				cnt++;
			}
			ans+=a[x][i];
			if (cnt==n)
			{
				if (l==1)
				{
					cout<<ans;
				}
				l=0;
			}
			f[x][i]=0;
			f[i][x]=0;
			dfs(i,ans);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			a[i][j]=-1;
		}
	}
	for (i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		f[u][v]=1;
		f[v][u]=1;
	}
	for (i=1;i<=k;i++)
	{
		cin>>c[i][1];
		for (j=1;j<=n;j++)
		{
			cin>>c[i][j+1];
		}
	}
	g[1]=1;
	dfs(1,0);
	return 0;
}