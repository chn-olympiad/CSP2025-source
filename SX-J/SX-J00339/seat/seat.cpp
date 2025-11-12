#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n = 0, m = 0, a, c, f, g, r;
	cout << n << m << endl;
	a = n * m;
	int b[a] = {};
	for (int i = 0; i < a; i++) {
		cin >> c;
		b[i] = c;
	}
	f = b[0];
	for (int i = 0; i < a; i++) {
		c = b[i];
		for (int d = 0; d < a; d++) {
			if (b[i] < b[d]) {
				g = b[i];
				b[i] = b[d];
				b[d] = g;
			}
		}
	}
	for (int i = 0; i < a; i++) {
		if (b[i] == f) {
			f = i + 1;
		}
	}
	if (f <= n) {
		c = 1;
		r = f;
		cout << c << " " << r;
	} else {
		c = f / n;
		if (c % 2 == 0) {
			if (f / n == 0) {
				r = 1;
				cout << c << " " << r;
			} else {
				r = f % n;
				cout << c << " " << r;
			}

		} else {
			if (f / n == 0) {
				r = n;
				cout << c << " " << r;
			} else {
				r = f % n;
				r = n - r + 1;
				cout << c << " " << r;
			}
		}
	}
	return 0;
}
