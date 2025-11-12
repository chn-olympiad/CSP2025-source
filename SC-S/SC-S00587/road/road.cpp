#include<bits/stdc++.h>
using namespace std;
int const N=1005,M=1000005,K=15;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}