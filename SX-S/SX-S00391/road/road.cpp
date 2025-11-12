#include <bits/stdc++.h>
using namespace std;
long long int w[1000002];
long long int c[12];

//图论 最小=n-1加权
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v >> w[i];
	}
	long long int ans = 0;
	sort(w + 1, w + m + 1);
	for (int i = 1; i <= n - 2; i++) {
		ans += w[i];
	}
	long long int x[1000002] = {0};
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		long long int a[1000002] = {0};
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + m + 1);
		x[j] = a[1] + a[2] + c[j];
	}
	sort(x + 1, x + 1 + k);
	if (w[n - 1] > x[1]) {
		cout << ans + x[1];
		return 0;
	} else {
		cout << ans + w[n - 1];
		return 0;
	}
}