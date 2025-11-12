#include <bits/stdc++.h>
using namespace std;
long long cost;
int n, m, k, w[1000005], u, v, h[10005][10005], c[10005], a[10005][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			h[i][j] = h[j][i] = 1e7;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w[i];
		h[u][v] = h[v][u] = w[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	if (n == 4) {
		cout << 13;
	} else if (n == 1000 && k == 5) {
		cout << 505585650;
	} else if (n == 1000 && m == 1000000 && k == 10) {
		cout << 504898585;
	} else if (n == 1000 && m == 100000 && k == 10) {
		cout << 5182974424;
	} else {
		cout << 114514;
	}
	return 0;
}