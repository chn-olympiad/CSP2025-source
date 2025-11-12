#include <bits/stdc++.h>
using namespace std;
int n, m, k, dis[10005][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dis[i][j] = 0x7ffffff;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;

	}
	for (int q = 1; q <= n; q++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][q] + dis[q][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += dis[i][j];
		}
	}
	cout << ans;
	return 0;
}
