#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum;

int u, v, w, f[1001][1001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		u = min(u, v);
		v = max(u, v);
		if (f[u][v] != 0) {
			f[u][v] = min(w, f[u][v]);
		} else
			f[u][v] = w;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			sum += f[i][j];
		}
	}
	cout << sum;
	return 0;
}

