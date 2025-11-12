#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
int t, n, a[N][4], mx[N], s[4], c[N];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
		memset(mx, 0, sizeof(mx));
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			mx[i] = max(max(a[i][1], a[i][2]), a[i][3]);
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				s[1]++;
				c[i] = mx[i] - max(a[i][2], a[i][3]);
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				s[2]++;
				c[i] = mx[i] - max(a[i][1], a[i][3]);
			} else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
				s[3]++;
				c[i] = mx[i] - max(a[i][1], a[i][2]);
			}
		}
		if (s[1] <= n / 2 && s[2] <= n / 2 && s[3] <= n / 2) {
			for (int i = 1; i <= n; i++) {
				ans += mx[i];
			}
			cout << ans << '\n';
		} else {
			int x;
			if (s[1] > n / 2) x = 1;
			else if (s[2] > n / 2) x = 2;
			else x = 3;
			int tt = s[x] - n / 2;
			for (int j = 1; j <= tt; j++) {
				int minn = 1e9, xx;
				for (int i = 1; i <= n; i++) {
					if (mx[i] == a[i][x]) {
						if (c[i] < minn) {
							minn = c[i];
							xx = i;
						}
					}
				}
				ans -= minn;
				c[xx] = 1e9;
			}
			for (int i = 1; i <= n; i++) {
				ans += mx[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
// 2025 CSP-J/S rp++
// awa
