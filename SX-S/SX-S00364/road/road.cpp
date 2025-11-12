#include <bits/stdc++.h>
using namespace std;
long long ans, ed[10005][10005], p[10025], hs[10025], n, m, kk, u, v, w, c;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> kk;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				ed[i][j] = LONG_LONG_MAX;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ed[u][v] = w;
		ed[v][u] = w;
	}
	for (int j = 1 + n; j <= kk + n; j++) {
		cin >> c;
		for (int k = 1; k <= n; k++) {
			cin >> ed[j][k];
			ed[k][j] = ed[j][k];
		}
	}
	for (int k = 1; k <= n + kk; k++) {
		for (int i = 1; i <= n + kk; i++) {
			for (int j = 1; j <= n + kk; j++) {
				if (ed[i][j] > ed[i][k] + ed[k][j]) {
					ed[i][j] = LONG_LONG_MAX;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ed[i][j] != LONG_LONG_MAX)
				ans += ed[i][j];
		}
	}
	cout << ans;
	return 0;
}
