#include <bits/stdc++.h>
using namespace std;
int n, a[6000], m, sum, b = 0, h;

int f(int x, int y) {
	int c, d = 1, e;
	c = y;
	for (int i = 1; i < x; i++) {
		c = c * (y - i);
		d = d * (i + 1);
	}
	e = c / d;
	return e;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		m = max(m, a[i]);
		sum = sum + a[i];
	}
	if (n == 3) {
		if (sum > 2 * m)
			cout << 1;
		if (sum <= 2 * m)
			cout << 0;
	}
	if (n != 3) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)
				b++;
		}
		if (b = n) {
			for (int j = 3; j <= n; j++) {
				h += f(j, n);
			}
		}
		cout << h;
	}
}
