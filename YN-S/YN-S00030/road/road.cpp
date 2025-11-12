#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int n, m, k, a[N][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int ans = 0;

	for (int i = 1; i <= m; i++) {

		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
		a[u][v] = w;
		a[v][u] = w;
		a[i][i] = 0;
	}

	for (int i = 1; i <= k; i++) {

		int c, b[k];
		cin >> c;

		for (int j = 1; j <= n; j++) {

			cin >> b[j];

			for (int k = j - 1; k >= 1; k--) {

				a[j][k] = a[k][j] = min(a[k][j], b[j] + b[k] + c);
			}
		}
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			if (i == j)
				continue;
		}
	}

	cout << ans;
	return 0;
}