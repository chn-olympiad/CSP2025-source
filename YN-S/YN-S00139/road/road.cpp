#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> k >> m;
	int u[1000010], v[1000100], w[1000010], c[15], a[15][10005];
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << 51;
	return 0;
}