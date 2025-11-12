#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105], s = 0, d = 1, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		for (int j = 1; j <= n * m; j++) {
			if (a[i] >= s) {
				d += 1;
				s = a[i];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (d <= n)
			x = 1;
		if (n < d <= m * n)
			x = i;
	}
	if (d <= n)
		y = d;
	if (x % 2 == 0)
		y = d - x * n;
	if (x % 2 == 1)
		y = x * n - d + 1;
	cout << x << ' ' << y;
	return 0;
}
