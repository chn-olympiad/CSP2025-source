#include <bits/stdc++.h>
using namespace std;
int n, m, i = 0, a1, x, y, h, c = 0, r = 0;
int a[10000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	for (i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	a1 = a[0];
	for (x = 0; x < m * n; x++) {
		for (y = 0; y < x; y++) {
			if (a[x] > a[y]) {
				h = a[x];
				a[x] = a[y];
				a[y] = h;
			}
			
		}
	}
	for (x = 0; x < m * n; x++) {
		if (a[x] == a1) {
			h = x + 1;
		}
	}
	if (h / n <= 1) {
		c = 1;
	} else {
		c = h / n + 1;
	}
	c = h / n;
	if (c % 2 == 0) {
		r = h - c * n;
	} else if (c % 2 != 0) {
		if (c == 1) {
			r = h;
		} else {
			r = h - c * n + 1;
		}

	}
	cout << h << endl;
	cout << c << " " << r << endl;
	return 0;
}
