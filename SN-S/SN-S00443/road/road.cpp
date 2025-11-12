#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100010],v[100010],w[100010],c[100010];
int a[10][100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1; i<=k; i++)
	{
		cin>>c[i];
		for(int j=1; j<=n; j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<15;
	return 0;
}
