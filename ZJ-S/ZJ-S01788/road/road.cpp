#include <iostream>
using namespace std;
int n,m,k,cst;
int city[10011][10011],cc[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		for(int j=1;j<=n+k;j++)
		{
			city[i][j]=0x3f;
			city[j][i]=0x3f;
		}
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		city[u][v]=w;
		city[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cc[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			city[n+i][j]=w;
			city[j][n+1]=w;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=n+k;l++)
			{
				if(l==i||l==j)continue;
				if(l<=n)
				{
					city[i][j]=city[j][i]=min(city[i][j],city[i][l]+city[j][l]);
				}
				else
				{
					city[i][j]=city[j][i]=min(city[i][j],city[i][l]+city[j][l]+cc[k-l]);
				}
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		cst+=city[i][i+1];
	}
	cout<<cst;
	return 0;
}
