#include<bits/stdc++.h>
using namespace std;

int n, m, k, a[15][10005];
vector<pair<int, int>>g[10005];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w}), g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) for (int j = 0; j <= n; j++) cin >> a[i][j];
	
}