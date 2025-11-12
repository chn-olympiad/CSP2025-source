#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T, n, a[maxn][5], m[maxn], lm[maxn], cnt[5];
struct N {
	int id, x;
	bool operator < (const N tmp) const {
		return x > tmp.x;
	}
} c[maxn];
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		memset(m, 0, sizeof(m));
		memset(lm, 0, sizeof(lm));
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > a[i][m[i]]) {
					lm[i] = m[i];
					m[i] = j;
				} else if (a[i][j] > a[i][lm[i]]) {
					lm[i] = j;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			c[i].x = a[i][m[i]] - a[i][lm[i]];
			c[i].id = i;
		}
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {
			if (cnt[m[c[i].id]] < n / 2) {
				ans += a[c[i].id][m[c[i].id]];
				cnt[m[c[i].id]]++;
			} else {
				ans += a[c[i].id][lm[c[i].id]];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}