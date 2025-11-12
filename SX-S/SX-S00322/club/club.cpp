#include <bits/stdc++.h>
using namespace std;
int m, n, a[100005], b[100005], c[100005], f[100005], s[100005], t[100005], cnt1, cnt2, cnt3, ans, sum1, sum2, sum3;
int cum;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out ", "w", stdout);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
			f[j] = max(a[j], max(b[j], c[j]));
			t[j] = min(a[j], min(b[j], c[j]));
			s[j] = a[j] + b[j] + c[j] - t[j] - f[j];
		}
		for (int j = 1; j < n; j++) {
			if (a[j] == f[j])
				sum1++;
			if (b[j] == f[j])
				sum2++;
			if (c[j] == f[j])
				sum3++;
		}

		if (sum1 > n / 2 or sum2 > n / 2 or sum3 > n / 2) {
			sort(f + 1, f + n + 1);
			for (int j = n; j > n / 2; j--) {
				ans += f[j];
			}
		} else {
			for (int j = 1; j <= n; j++) {
				if (cnt1 <= n / 2 and f[j] == a[j]) {
					ans += a[j];
					cnt1++;
				}
				if (cnt2 <= n / 2 and f[j] == b[j]) {
					ans += b[j];
					cnt2++;
				}
				if (cnt3 <= n / 2 and f[j] == c[j]) {
					ans += c[j];
					cnt3++;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			f[j] = 0;
			s[j] = 0;
			t[j] = 0;
		}
		cout << ans << "\n";
		ans = cnt1 = cnt2 = cnt3 = 0;
	}

	return 0;
}
