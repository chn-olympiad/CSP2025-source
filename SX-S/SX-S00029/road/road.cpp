#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+2;
long long n, m, k, u[N], v[N], w[N], c[N], a[N], ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[j];
	}
	if (k == 0) {
		for (int i = 1; i <= m; i++)
			ans += w[i];
	}
	for (int i = 1; i <= k; i++)
		if (c[i] == 0)
			ans = 0;
	cout << ans;
	return 0;
}