#include <bits/stdc++.h>;
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[101], b[11][11] = {0}, x = 0, y = 0, z = 0, o = 0, p = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	for (int i = n * m; i >= 1; i--) {
		z++;
		for (int j = m * n - z; j >= 1; j--) {
			if (a[i] > a[j]) {
				y = a[j];
				a[j] = a[i];
				a[i] = y;
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (x == a[i]) {
			x = i;
		}
	}
	if (x % n != 0) {
		o = x / n + 1;
	} else {
		o = x / n;
	}
	if (o % 2 != 0) {
		if (x % n == 0) {
			p = n;
		} else {
			p = x % n;
		}
	} else {
		if (x % n == 0) {
			p = 1;
		} else {
			p = m - x % n + 1;
		}
	}
	cout << o << " " << p;
	return 0;
}