#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, l, h, max = 0, a[105] = {};
	cin >> n >> m;
	for (int i = 0; i <= n * m; i++) {
		cin >> a[i];
		int b[i] = {};
		if (a[i] > b[i]) {
			b[i] = a[i];

//			cout << b[i];
			if (a[0] = b[i]) {
				if (i % n == 0) {
					l = i / n;
				} else {
					l = i / n + 1;
				}
				if (l % 2 == 0) {
					cout << l << " " << n;
				} else {
					cout << l << " " << n - (i - l *n);
				}
			}

		}
	}
}
