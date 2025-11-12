#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 20;
long long n, m, k, ans = 0, mp[N][N], build[105];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(mp, 0x3f, sizeof(mp));
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			ans += w;
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = w;
		mp[v][u] = w;
		ans += w;
	}
	for (int i = n + 1; i <= n + k; i++) {
		cin >> build[i - n];
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
			mp[j][i] = mp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int o = 1; o <= n; o++) {
				if (mp[i][j] > mp[i][o] + mp[o][j]) {
					if (mp[i][j] < 1e9 + 10) {
						ans -= mp[i][j];
					}
					mp[i][j] = mp[i][o] + mp[o][j];
				}
			}
			for (int o = n + 1; o <= n + k; o++) {
				if (mp[i][j] > mp[i][o] + mp[o][j] + mp[i][j] + build[o - n]) {
					if (mp[i][j] < 1e9 + 10) {
						ans -= mp[i][j];
					}
					mp[i][j] = mp[i][o] + mp[o][j] + build[o - n];
					build[o - n] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}