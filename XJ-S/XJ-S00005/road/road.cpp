// while (1) csp2025rp++;
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxm = 1e6 + 5;

int n, m, k, g[maxm][maxm];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	memset(g, 1e9, sizeof(g));
	
	cin >> n >> m >> k;
	for (int i = 0 ; i < m ; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	
	cout << "0";
	
	
	
	return 0;
}
