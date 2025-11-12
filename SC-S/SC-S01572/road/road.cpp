#include <bits/stdc++.h>
using namespace std;
long long mp[1010][1010];
long long vis[1010][1010];
long long c[1010][1010], h[100010]; 
long long f[100010];
long long n, m, k;
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; ++i) {
		long long u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = w, mp[v][u] = w;
	}
	for (long long j = 1; j <= k; ++j) {
		cin >> f[j];
		for (long long i = 1; i <= n; ++i) {
			cin >> c[j][i];
		}
	}
	long long ans = 0;
	for (long long T = 1; T <= n - 1; ++T) {
		long long minyyy = 0x7ffffff, flag = 0, scsc = 0, dx, dy;
		for (long long i = 1; i <= T; ++i) {
			for (long long j = 1; j <= n; ++j) {
				if (j == i || vis[i][j] == 1) continue;
				long long fway1 = mp[i][j], fway2 = 0x7ffffff, lllsc = 0;
				if (mp[i][j] == 0) fway1 = 0x7ffffff;
				for (long long g = 1; g <= k; ++g) {
					if (h[g] == 0) {
						if (f[g] + c[g][i] + c[g][j] <= fway2) {
							fway2 = f[g] + c[g][i] + c[g][j];
							lllsc = g;
						}
					}else{
						if (c[g][i] + c[g][j] <= fway2) {
							fway2 = f[g] + c[g][i] + c[g][j];
							lllsc = g;
						}
					}
				}
				if (fway2 <= fway1) {
					if (fway2 <= minyyy) {
						minyyy = fway2;
						flag = 1, scsc = lllsc;
						 dx = i, dy = j;
					}
				}else{
					if (fway1 <= minyyy) {
						minyyy = fway1;
						flag = 0;
						dx = i, dy = j;
					}
				}
			}
		}
		ans += minyyy;
//		cout << dx << ' ' << dy << ' ' << scsc << ' ' << minyyy << endl;
		vis[dx][dy] = 1, vis[dy][dx] = 1;
		if (flag == 1) {
			h[scsc] = 1;
		}
	}
	cout << ans;
	return 0;
}