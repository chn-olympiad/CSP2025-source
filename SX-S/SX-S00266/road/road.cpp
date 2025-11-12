#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[12],a[12][1005];
map <int,map<int,int>> p;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{
		cin >> u >> v >> w;
		p[u][v]=w;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	
	return 0;
}
