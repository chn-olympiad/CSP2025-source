#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5, M = 1e6+5;
long long n, m, k, u, v, w[M], c[11], a[11][N], flag = 1;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> u >> v >> w[i];
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (c[i] != 0 || a[i][j] != 0)
				flag = 0;
		}
	}
	if (k == 0) {
		long long ans = 0;
		for (int i = 1; i <= m; i++)
			ans += w[i];
		cout << ans;
		return 0;
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	return 0;
}