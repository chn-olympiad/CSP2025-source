#include <bits/stdc++.h>
using namespace std;
struct node1 {
	int s, k;
}a[100010][4];
struct node2 {
	int x, c, r;
}f[100010];
int vis[100010][4], p[4];
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1].s >> a[i][2].s >> a[i][3].s;
			a[i][1].k = 1, a[i][2].k = 2, a[i][3].k = 3;
			for (int j = 1; j <= 3; ++j) {
				if(a[i][j].s > f[i].r) {
					f[i].r = a[i][j].s;
					f[i].c = j;
				}
			}
			f[i].x = i, p[f[i].c]++, vis[i][f[i].c] = 1;
		}
		while (1) {
			bool flag = true;
			int u = 0, mink = 0x7ffffff, step = 0, clubc = 0;
			for (int i = 1; i <= 3; ++i) {
				if (p[i] > n / 2) {
					u = i, flag = false;
					break;
				}
			}
			if (flag == true) break;
			for (int i = 1; i <= n; ++i) {
				if (f[i].c == u) {
					for (int j = 1; j <= 3; ++j) {
						if (vis[i][j] == 0) {
							if (f[i].r - a[i][j].s < mink) {
								mink = f[i].r - a[i][j].s;
								step = i, clubc = j;
							}
						}
					}
				}
			}
			vis[step][clubc] = 1;
			f[step].c = clubc, f[step].r = a[step][clubc].s;
			p[u]--, p[clubc]++;
		}
		for (int i = 1; i <= n; ++i) ans += f[i].r;
		cout << ans << endl;
		for (int i = 1; i <= 3; ++i) p[i] = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= 3; ++j) vis[i][j] = 0;
		for (int i = 1; i <= n; ++i) f[i].x = 0, f[i].c = 0, f[i].r = 0;
	}
	return 0;
}