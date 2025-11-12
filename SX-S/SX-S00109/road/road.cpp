#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
long long n, m, K, u, v, w;
long long a[1011][1011], c, b;
long long ans;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> K;
	for (int i = 1; i <= n + K; i++)
		for (int j = 1; j <= n + K; j++)
			if (i != j)
				a[i][j] = INF;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = min(a[u][v], w);
	}

	for (int i = 1; i <= K; i++) {
		cin >> c;
		a[n + i][n + i] = c;
		for (int j = 1; j <= n; j++) {
			cin >> b;
			a[n + i][j] = a[j][n + i] = b ;
		}
	}
	for (int k = 1; k <= n + K; k++) {
		for (int i = 1; i <= n ; i++) {
			for (int j = 1; j <= n  ; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j] + a[k][k]);
			}
		}
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n  ; j++) {
			ans = max(ans, a[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
