#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, a[5010], s = 0, maxx = LLONG_MIN, ans = 0, h, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			t = 1;
		}
	}
	if (t == 0) {
		cout << n - 2;
		return 0;
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			s = s + a[i];
			if (a[i] > maxx) {
				maxx = a[i];
			}
		}
		if (s > maxx * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		s = 0;
		h++;
		maxx = LLONG_MIN;
		for (int j = 1; j <= n - h; j++) {
			s = s + a[i];
			if (a[i] > maxx) {
				maxx = a[i];
			}
			if (s > maxx * 2) {
				ans++;
				maxx = LLONG_MIN;
			}
		}

	}
	cout << ans % 998244353;
	return 0;
}
