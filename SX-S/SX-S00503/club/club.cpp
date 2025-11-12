#include <bits/stdc++.h>
using namespace std;
int t, a[100005][10];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++) {
			int zd = -1, zx = 1e8, bz = 0, dii, djj, xii, xjj, zii, zjj;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] > zd) {
					zd = a[i][j];
					dii = i;
					djj = j;
				}
				if (a[i][j] < zx) {
					zx = a[i][j];
					xii = i;
					xjj = j;
				}
			}
			bz = a[i][1] + a[i][2] + a[i][3] - zd - zx;
			for (int j = 1; j <= 3; j++)
				if (a[i][j] == bz)
					zii = i, zjj = j;
			a[dii][djj] -= bz;
			a[xii][xjj] = 0;
			a[zii][zjj] = 0;
			ans += bz;
		}
		for (int j = 1; j <= 3; j++) {
			int zd = -1, id11, id22, c = n / 2;
			for (int k = 1; k <= c; k++) {
				zd = -1;
				for (int i = 1; i <= n; i++) {
					if (a[i][j] > zd ) {
						zd = a[i][j];
						id11 = i;
						id22 = j;
					}
				}
				ans += zd;
				a[id11][id22] = 0;
			}
		}
		cout << ans << endl;
		memset(a, 0, sizeof(a));
	}
	return 0;
}
