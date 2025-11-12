#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[100100], v[100100], w[100100], c[20], h[20][100100], l = -1;
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> v[i] >> u[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		l = max(c[i], l);
		for (int j = 1; j <= n; j++) {
			cin >> h[i][j];
		}
	}
	if (l == 0) {
		cout << 0;
		return 0;
	}
	sort(w + 1, w + m + 1);
	for (int i = 1; i < n; i++) {
		ans += w[i];
	}
	cout << ans;
	return 0;
}
