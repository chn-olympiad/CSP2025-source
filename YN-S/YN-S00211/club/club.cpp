#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n;
int AA[N];
int f[N][5], cnt[N], a[N][5];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (; T--;) {
		cin >> n;
		int zb = 0, zc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			AA[i] = a[i][0];
			if (a[i][1] == 0)
				zb++;
			if (a[i][2] == 0)
				zc++;
		}
		if (zb == n && zc == n) {
			int sum = 0;
			sort(AA + 1, AA + n + 1, greater<int>());
			for (int i = 1; i <= n / 2; i++) {
				sum += AA[i];
			}
			cout << sum << "\n";
		} else {
			for (int i = 1; i <= n; i++) {
//				cin >> a[i][0] >> a[i][1] >> a[i][2];
				f[i][0] = f[i][1] = f[i][2] = 0;
				cnt[0] = cnt[1] = cnt[2] = 0;
			}
			f[1][0] = f[1][1] = f[1][2] = 0;
			for (int i = 1; i <= n; i++) {
				int A = 0, B = 0, C = 0;
				A = a[i][0], B = a[i][1], C = a[i][2];
				int Max = max({A, B, C});
				if (Max == A) {
					if (cnt[0] <= n / 2) {
						f[i][0] = max(f[i - 1][0], f[i][0] + a[i][0]);
						cnt[0]++;
					}
				} else if (Max == B) {
					if (cnt[1] <= n / 2) {
						f[i][1] = max(f[i - 1][1], f[i][1] + a[i][1]);
						cnt[1]++;
					}
				} else {
					if (cnt[2] <= n / 2) {
						f[i][2] = max(f[i - 1][2], f[i][2] + a[i][2]);
						cnt[2]++;
					}
				}
			}
			int res = 0;
			for (int i = 1; i <= n; i++) {
//			cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << "\n";
				res += f[i][0];
				res += f[i][1];
				res += f[i][2];
			}
			cout << res << "\n";
		}
	}
	return 0;
}