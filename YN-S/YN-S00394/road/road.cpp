#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, a[1000000], h = 0;
	cin >> n >> m >> k;
	int b = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n - 1; j++) {
			cin >> u >> v >> w;
		}
		for (int z = 1; z <= k; z++) {
			cin >> a[z];
			if (a[z] < b) {
				b = a[z];
			}
		}
		if (u == n) {
			h = h + w;
		}
	}
	cout << h + b + a[b - 1];

	return 0;
}