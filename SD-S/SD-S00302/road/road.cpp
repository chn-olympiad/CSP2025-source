#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		w[i]+=w[i-1];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<w[m];
	return 0;
}
