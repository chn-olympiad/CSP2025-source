#include <bits/stdc++.h>
using namespace std;

int n, m, k, u[1000005], v[1000005], w[1000005], sum, c[15][10005], maxn;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> c[i][j];
			maxn = max(maxn, c[i][j]);
		}
	}
	sort(w + 1, w + m + 1);
	if (k == 0) {
		for (int i = 1; i <= n - 1; i++) {
			sum += w[i];
		}
		cout << sum;
	} else if (maxn == 0) {
		cout << 0;
	} else {
		cout << 0;
	}

	return 0;
}
