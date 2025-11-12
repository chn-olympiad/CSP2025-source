#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			int b;
			cin >> b;
		}
	}
	cout << sum;
	return 0;
}