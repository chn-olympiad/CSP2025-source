#include<bits/stdc++.h>
using namespace std;
int tim, n;
const int maxn = 1e6+10;
int a[1010][4];
int f[1010][1010];
int cnt[4];
int G[maxn];
int getexP(int p, int i) {
	if (p == 1)return max(a[i][2], a[i][3]);
	if (p == 2)return max(a[i][1], a[i][3]);
	return max(a[i][1], a[i][2]);
}
void solve() {
	cnt[1] = 0, cnt[2] = 0, cnt[3] = 0;
	cin >> n;

	if (n <= 200) {
		for (int i = 1; i <= n; i++)cin >> a[i][1] >> a[i][2] >> a[i][3];
		int res = 0;
		for (int p = 1; p <= 3; p++) {

			for (int i = 1; i <= n; i++) {
				f[0][i] = -2000000000;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					if(j>i)f[i][j]=-2000000000;
					if (j) {
						f[i][j] = max(f[i - 1][j] + getexP(p, i), f[i - 1][j - 1] + a[i][p]);
					} else {
						f[i][j] = f[i - 1][j] + getexP(p, i);
					}
				}
			}
			res = max(res, f[n][n / 2]);
		}
		int ans = 0;
		bool ned = false;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				if (cnt[1] != n / 2) {
					ans += a[i][1];
					cnt[1]++;
				} else {
					ned = true;
					break;
				}
			} else if (a[i][2] >= a[i][3]) {
				if (cnt[2] != n / 2) {
					ans += a[i][2];
					cnt[2]++;
				} else {
					ned = true;
					break;
				}
			} else {
				if (cnt[3] != n / 2) {
					ans += a[i][3];
					cnt[3]++;
				} else {
					ned = true;
					break;
				}
			}
		}
		if (ned)cout << res << '\n';
		else cout << ans << '\n';
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> G[i];
		}
		sort(G + 1, G + 1 + n);
		int ans = 0;
		for (int i = n; i > n / 2; i--)ans += G[i];
		cout << ans << '\n';
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> tim;
	while (tim--) {
		solve();
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/