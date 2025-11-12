#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e4 + 10;
int n, m, k, ans = 0;
int u[N], v[N], w[N];
int c[15], a[15][M];

signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	int ans = 0, sum = 0;
	for (int j = 1; j <= k; j++) {
		ans = max(ans, sum);
		sum = c[j];
		for (int i = 1; i <= n; i++) {
			sum += a[j][i];
		}
	}
	cout << ans;
	return 0;
}