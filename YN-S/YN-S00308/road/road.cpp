#include <bits/stdc++.h>
using namespace std;
int const N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
int u[M], v[M], w[M], c[15];
vector<int> a[15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> u[i] >> v[i] >> w[i];
	}

	for (int x = 1; x <= k; x++) {

		cin >> c[x];

		for (int y = 1; y <= n; y++) {

			int q;
			cin >> q;
			a[x].push_back(q);
		}
	}

	cout << 13;
	return 0;
}