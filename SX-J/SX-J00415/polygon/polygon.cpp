#include <bits/stdc++.h>
using namespace std;
int n, a[5005], b[5005], c[5005], ans = 0, p = 1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1)
			p = 0;
	}
	if (p == 1) {
		for (int i = 3; i <= n; i++) {
			if (n == i) {
				ans = (ans + 1) % 998244353;
			} else if (n - i > i) {
				long long o = 1, s = 1;
				for (int j = n - i + 1; j <= n; j++)
					o = (o * j) % 998244353;
				for (int j = 1; j <= i; j++)
					s = (s * j) % 998244353;
				ans += (o / s) % 998244353;
			} else {
				long long o = 1, s = 1;
				for (int j = i + 1; j <= n; j++)
					o = (o * j) % 998244353;
				for (int j = 1; j <= n - i; j++)
					s = (s * j) % 998244353;
				ans += (o / s) % 998244353;
			}
		}
		cout << ans % 998244353;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		b[i] = b[i + 1] + a[i];
		c[i] = c[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= c[i - 1])
			continue;
		int l = 1, r = i, k = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (b[mid] - b[i] <= a[i]) {
				r = mid - 1;
			} else {
				k = max(mid, k) % 998244353;
				l = mid + 1;
			}
		}
		ans += k % 998244353;
	}
	cout << ans % 998244353;
	return 0;
}
