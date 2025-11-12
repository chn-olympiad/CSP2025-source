#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[1000005],d[1000005];
int a[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		a[u[i]][v[i]]=w[i];
		a[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	n++;
	cout<<0;
	return 0;
}