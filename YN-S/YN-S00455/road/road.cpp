#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e4 + 10;
long long int c[N][N];
long long int ansl;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, x, y, t;
	long long z;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		t = c[min(x, y)][max(x, y)];
		c[min(x, y)][max(x, y)] = min(c[min(x, y)][max(x, y)], z);
		if (t != c[min(x, y)][max(x, y)]) {
			ansl += c[min(x, y)][max(x, y)];
		}
	}
	for (int i = 1; i <= k; i++) {
		int p;
		for (int i = 1; i <= n + 1; i++) {
			cin >> p;
		}
	}
	cout << ansl;
	return 0;
}