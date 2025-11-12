#include <bits/stdc++.h>
using namespace std;
long long t, n, a, b, c, d, e, f, mx1, mx2, xb1, xb2, mn1, mn2;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b >> c >> d >> e >> f;
		mx1 = max(a, max(b, c));
		if (mx1 == a) {
			xb1 = 1;
			mn1 = max(b, c);
		} else if (mx1 == b) {
			xb1 = 2;
			mn1 = max(a, c);
		} else if (mx1 == c) {
			xb1 = 3;
			mn1 = max(a, b);
		}
		mx2 = max(d, max(e, f));
		if (mx2 == d) {
			xb2 = 1;
			mn2 = max(e, f);
		} else if (mx2 == e) {
			xb2 = 2;
			mn2 = max(d, f);
		} else if (mx2 == f) {
			xb2 = 3;
			mn2 = max(d, e);
		}
		if (xb1 != xb2)
			cout << mx1 + mx2;
		if (xb1 == xb2) {
			if (mx1 > mx2)
				cout << mx1 + mn2;
			if (mx1 < mx2)
				cout << mx2 + mn1;
			if (mx1 == mx2)
				cout << mx1 + mn2;
		}
	}
	return 0;
}
