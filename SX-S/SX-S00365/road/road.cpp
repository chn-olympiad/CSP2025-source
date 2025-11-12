#include <bits/stdc++.h>
using namespace std;
bool fix[15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	int anser = 0;
	cin >> n >> m >> k;
	int a[n + 1][n + 1];
	int c[k + 1];
	int b[n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0x3f;
			if (i == j) {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
		anser += w;
	}
	for (int i = 1; i <= k; i++) {
		int c1;
		cin >> c1;
		for (int j = 1; j <= n; j++) {
			int a1;
			cin >> a1;
		}
	}
	cout << anser;
}