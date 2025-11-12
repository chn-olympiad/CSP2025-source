#include <bits/stdc++.h>
using namespace std;
int u[100000], v[100000], w[100000], c[100000];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, sum = 0;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> u[i] >> v[i] >> w[i];
		sum += w[i];
	}

	for (int i = 1; i <= k; i++) {

		for (int j = 1; j <= n + 1; j++) {

			cin >> c[i];
		}
	}

	cout << sum;
	return 0;
}
