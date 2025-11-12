#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
int a[1010][1010];
int v[1010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x][y] = z;
		a[y][x] = z;
	}
	int xzfy;
	int zs[n + 1];
	for (int i = 0; i < k; i++) {
		cin >> xzfy;
		for (int j = 1; j <= n; j++) {
			cin >> zs[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int k1 = j + 1; k1 <= n; k1++) {
				if (a[j][k1] != 0) {
					a[j][k1] = min(a[j][k1], xzfy + zs[j] + zs[k1]);
					a[k1][j] = min(a[k1][j], xzfy + zs[j] + zs[k1]);
				} else {
					a[j][k1] = xzfy + zs[j] + zs[k1];
					a[k1][j] = xzfy + zs[j] + zs[k1];
				}
			}
		}
	}
	int yy = 1;
	v[1] = 1;
	while (yy < n) {
		int zx = INT_MAX, zsxh;
		for (int i = 1; i <= n; i++) {
			if (v[i] == 1) {
				for (int j = 1; j <= n; j++) {
					if (a[i][j] < zx && a[i][j] != 0 && v[j] == 0) {
						zx = a[i][j];
						zsxh = j;
					}
				}
			}
		}
		yy++;
		ans += zx;
		v[zsxh] = 1;
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
