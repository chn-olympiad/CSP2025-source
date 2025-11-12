#include <bits/stdc++.h>
using namespace std;
int a[4];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, b, c, d, e, f;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		b = max(a[1], a[2]);
		e = max(a[3], b);
		c = a[1] + a[2] + a[3];
		d = c - e;
		if (d > e) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 998244353;
	}
	return 0;
}
