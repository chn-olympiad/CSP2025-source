#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, N1 = 15;
int n, yu, id, minn = INT_MAX, ans, m, k, u[N], v[N], w[N], a[N1], b[N1], c[N1], d[N1], e[N1];

int lj(int x, int y) {
	return x = y;
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout );
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		minn = min(minn, w[i]);
		if (minn == w[i]) {
			id = i;
		}
	}
	u[id] = v[id];
	ans += w[id];
	for (int i = 1; i <= k; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	for (int i = 1;; i++) {
		for (int j = 1; j <= n; j++) {
			yu = 0;
			if (a[j] != a[j + 1]) {
				yu = 1;
				break;
			}
		}
		if (yu == 0) {
			cout << ans;
			return 0;
		}
		for (int j = 1; j <= n; j++) {
			if (u[i] == v[j] || u[i] == u[j]) {
				lj(u[i], v[i]);
				ans += w[i];
			}
		}

	}
	cout << ans;
	return 0;
}