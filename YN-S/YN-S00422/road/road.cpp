#include <bits/stdc++.h>
using namespace std;
int n, m, ans, k, u[10005], v[10005], w[10005], a[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];

	}
	while (k--) {
		for (int i = 1; i <= n + 1; i++) {
			cin >> a[i];
		}
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m / 2; i++) {
		ans += w[i];
	}
	cout << ans;
	return 0;
}