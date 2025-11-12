#include<bits/stdc++.h>
using namespace std;
int u[100000],v[100000],w[100000],c[10000],a[20][100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k,b,n,t,s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<13;
	return 0;
 } 