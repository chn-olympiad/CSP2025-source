#include <bits/stdc++.h>
using namespace std;
int dist[10015][10005], c[15];
int sum = 0, y = 0;
int n, m, k, u, v, w, x;

void flo() {
	for (int i = 1; i <= n + k; i++) {
		for (int j = i; j <= n + k; j++) {
			for (int o = i; o <= j; o++) {
				if (i <= n && j > n) {
					y += c[j - n];
					c[j - n] = 0;
				}

				else if (i > n && j < n) {
					y += c[i - n];
					c[i - n] = 0;
				}

				dist[i][j] = min(dist[i][j], dist[i][o] + dist[o][j]);
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> x;
			dist[n + i][j] = x;
			dist[j][n + i] = x;
		}
	}
	flo();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum += dist[i][j];
		}
	}
	cout << sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/