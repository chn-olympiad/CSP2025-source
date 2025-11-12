#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1];
	int a[n+1][1];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<n+1;i++)
		{
			cin>>a[i][j];
		}
	}
}
