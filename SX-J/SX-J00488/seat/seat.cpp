#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, a[105];

int main() {
	freopen("seat.in", "r", std.in);
	freopen("seat.out", "w", std.out);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s, xr = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == xr) {
			s = n * m - i + 1;
		}
	}
	if (s % n == 0) {
		c = s / n;
	} else {
		c = s / n + 1;
	}
	if (c % 2 == 1) {
		if (s % n == 0) {
			r = n;
		} else {
			r = s % n;
		}
	} else {
		if (s % n == 0) {
			r == 1;
		} else {
			r = n - s % n + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}
