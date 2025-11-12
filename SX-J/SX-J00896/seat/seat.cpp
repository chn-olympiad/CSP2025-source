#include <bits/stdc++.h>
using namespace std;
int c, r, x, p = 1;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> c >> r;
	for (int i = 0; i < c * r; i++) {
		cin >> a[i];
		if (i == 0)
			x = a[i];
		if (a[i] > x)
			p += 1;
	}
	if (p % c == 0) {
		if ((p / c) % 2 == 1)
			cout << p / c << ' ' << r;
		else
			cout << p / c << ' ' << 1;
	} else {
		cout << p / c + 1 << ' ';
		if ((p / c + 1) % 2 == 0)
			cout << c - (p - (c + 1));
		else
			cout << p % c;
	}
	return 0;
}