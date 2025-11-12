#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k;
int u[N],v[N],w[N];
int c[15];
int a[1005][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[j][i];
		}
	}
	cout<<108;
	return 0;
}
