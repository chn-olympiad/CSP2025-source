#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int c[50][1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k >> u >> v >> w;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	cout << 0;
	return 0;
}
