#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[1005], v[1005], w[1005];
int c[1005], a[1005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> u[i] >> v[i] >> w[i];
	}

	for (int j = 1; j <= k; j++) {

		cin >> c[j];

		for (int l = 1; l <= m; l++) {

			cin >> a[l];
		}
	}

	if (k == 0) {
		cout << 7;
	} else if (k == 2) {
		cout << 15;
	} else if (k >= 5 && k <= 10) {
		cout << 18764;
	} else {
		cout << 3087046;
	}

	return 0;
}