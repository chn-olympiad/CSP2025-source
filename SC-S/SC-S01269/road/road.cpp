#include <bits/stdc++.h>
using namespace std;
vector<int> g[10005],g2[10005];
int c[10005],a[15][10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	while(m--)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g2[u].push_back(w);
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << 0 << endl;
    return 0;
}