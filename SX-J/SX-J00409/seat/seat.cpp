#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[1000], z, g = 1, x, y;
	cin >> n >> m;
	z = n * m;
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	for (int w = 2; w <= z; w++) {
		if (a[1] < a[w])
			g++;
	}
	x = g / n + 1;
	y = g % n;
	if (x % 2 == 1) {
		cout << x << " " << y;
	} else
		cout << x << " " << n - y + 1;
	return 0;
}