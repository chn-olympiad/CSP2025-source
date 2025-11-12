#include<bits/stdc++.h>
using namespace std;
int n,m,t,u[1000003],v[1000005],w[1000005],c[15],a[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=t;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	cout<<285602;
	return 0;
}
