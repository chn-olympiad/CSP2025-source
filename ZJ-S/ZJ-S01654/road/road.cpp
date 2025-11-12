#include<bits/stdc++.h>
using namespace std;
int dist[10010][10010];
const int INF = 1e18;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m,  k;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(i != j)
				dist[i][j] = INF;
	for(int i = 1; i <= n; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dist[u - 1][v - 1] = min(w, dist[u - 1][v - 1]);
		dist[v - 1][u - 1] = min(dist[v - 1][u - 1], w);
	}
	for(int i = 1; i <= m; i ++)
		for(int j = 0; j < n; j ++)
			for(int k = 0; k < n; k ++)
				if(dist[j][i] != INF && dist[i][k] != INF)
					dist[j][k] = min(dist[j][k], dist[i][k] + dist[j][i]);
	cout << dist[1][n] << endl;
	return 0;
}
