#include <bits/stdc++.h>
using namespace std;

int l = 0, t, n, a[100005], b[100005], c[100005];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t >> n;
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
		};
		sort(a, a + n );
		sort(b, b + n );
		sort(c, c + n );
		for (int h = n; h >= n / 2; h--) {
			if (a[h - 1] > b[h - 1] && c[h - 1]) {
				l += a[h - 1];
				if (b[h - 1] > c[h - 1]) {
					l += b[h - 1];
				} else
					l += c[h - 1];
			};
			if (b[h - 1] > a[h - 1] && c[h - 1]) {
				l += b[h - 1];
				if (a[h - 1] > c[h - 1]) {
					l += a[h - 1];
				} else
					l += c[h - 1];
			};
			if (c[h - 1] > a[h - 1] && b[h - 1]) {
				l += c[h - 1];
				if (a[h - 1] > b[h - 1]) {
					l += a[h - 1];
				} else
					l += b[h - 1];
			};
			cout << l;
		};
	};
	return 0;
}