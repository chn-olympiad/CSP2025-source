#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, a[1020][1020], x;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		for (int j = 1; j <= n + k; j++) {
			if (i != j)
				a[i][j] = INT_MAX;
		}
	}
	while (m--) {
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = min(a[u][v], w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> x;
		for (int j = 1; j <= n; j++) {
			cin >> w;
			a[m + j][j] = a[j][m + j] = min(a[m + j][j], w);
		}
	}

	for (int t = 1; t <= n; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][t] + a[t][j] < a[i][j])
					a[i][j] = a[i][t] + a[t][j];
			}
		}
	}
	cout << a[1][n];


	return 0;
}