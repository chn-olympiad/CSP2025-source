#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt;
int c[1000000005], a[1000005];
int u[10005], v[10005], w[1000000005];

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}

	for (int i = 1; i <= m - 1; i++) {
		if (w[i] <= w[i + 1]) {
			w[i + 1] = w[i];
			if (i == m - 1) {
				cnt += w[i] + w[i - 1];
			}
		}

	}

	cout << cnt;

	return 0;
}