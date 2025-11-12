#include <bits/stdc++.h>
using namespace std;
int a[105], i = 1, n, m, x, l;

main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (i; i <= n * m; i++) {
		cin >> a[i];
		if (a[1] < a[i]) {
			x++;
		}
	}
	if ((x / m) % 2 != 0) {
		l = m - x % m ;
	} else {
		l = x % m + 1;
	}
	cout << x / m + 1 << " " << l;
	return 0;
}