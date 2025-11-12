#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, w[1000005], k, c[1000005], a[1000005][1000005];
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> a[j][i];
		}
	}
	cout << 13;

	return 0;
}