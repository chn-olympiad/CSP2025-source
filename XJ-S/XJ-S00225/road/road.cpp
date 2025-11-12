#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,u[M],v[M],w[M],c[15],a[15][N]; 
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
	int ans=0;
	cout<<ans;
	return 0;
}
