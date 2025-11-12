#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int b = m + n;
	int a[b];
	for (int i = 1; i <= b; i++) {
		cin >> a[i];
	}
	int x, y, c, z;
	z = a[1];
	sort(a + 1, a + b + 1);
	for (int i = 1; i <= b; i++) {
		if (a[i] == z) {
			c = i;
		}
	}
	y = c % n;
	x = c / n;
	if (c % n != 0) {
		x++;
	}
	if (y == 0) {
		y++;
	}
	if (x % 2 == 0) {
		if (c % n != 0) {
			y = n - c % n + 1;
		} else if (c % n == 0) {
			y = n;
		}
	} else if (x % 2 != 0) {
		y = c % n;
	}
	cout << x << " " << y;
	return 0;
}