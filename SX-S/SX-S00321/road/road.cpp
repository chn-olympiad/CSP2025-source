#include <bits/stdc++.h>
using namespace std;
int n, m, ka[1000005], u[1000005], v[1000005], w[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> u[i] >> v[i] >> w[i];
		int au = a[u[i]];
		int av = a[v[i]];
		if (au == 0)
			a[u[i]] = av + w[i];
		if (av == 0)
			a[v[i]] = au + w[i];
		if (au != 0 && av != 0) {
			a[u[i]] = min(av + w[i], au);
			a[v[i]] = min(au + w[i], av);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i])
			ans = max(ans, a[i]);
	}
	cout << ans;
	return 0;
}