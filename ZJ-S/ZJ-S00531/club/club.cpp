#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, T, a[N][3], cnt[3], b[N], mx[N];
inline void solve() {
	cin >> n;
	memset(cnt, 0, sizeof cnt);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int p = 0;
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			if (a[i][j] > a[i][p])
				p = j;
		}
		mx[i] = p, ans += a[i][p], cnt[p]++;
	}
	int m = 0;
	for (int i = 0; i < 3; i++)
		if (cnt[i] > cnt[m])
			m = i;
	if (cnt[m] > (n / 2)) {
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if (mx[i] == m) {
				int dec = 2e4;
				for (int j = 0; j < 3; j++)
					if (j != m)
						dec = min(dec, a[i][m] - a[i][j]);
				b[++k] = dec;
			}
		}
		nth_element(b + 1, b + (cnt[m] - n / 2), b + k + 1);
		for (int i = 1; i <= cnt[m] - n / 2; i++)
			ans -= b[i];
	}
	cout << ans << '\n';
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
		solve();
	return 0;
}