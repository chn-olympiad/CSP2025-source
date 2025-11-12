#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
int n, m, k, u, v, w, c[N], a[N][N], dist[N][N], cnt;
void floyd()
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
	}
	for(int j = 1; j <= k; j++)
	{
		cin >> c[j]; 
		for(int i = 1; i <= n; i++)
		{
			cin >> a[j][i];
			dist[j][i] = a[j][i];
		}
	}
	floyd();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cnt += dist[i][j];
		}
	}
	cout << cnt;
	return 0;
}
