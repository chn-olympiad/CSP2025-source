#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000010], v[1000010], w[1000010], c[11], a[11][10010];
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	cout << ans;
	return 0;
}
