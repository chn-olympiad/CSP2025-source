#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int u,v,w;
int a[10005][10005];
int b[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				b[i][j]=min(b[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int minn=INT_MAX;
		for(int j=1;j<=n;j++)
		{
			minn=min(minn,a[i][j]);
		}
		cnt+=minn;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
