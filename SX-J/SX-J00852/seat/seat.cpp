#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, zw, xr;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a[110] = {0};
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	xr = a[0];
	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m ; j++) {
			if (a[i] > a[j]) {
				int b = a[j];
				a[j] = a[i];
				a[i] = b;
			}
		}
	}

	for (int i = 0; i < n * m; i++) {
		if (a[i] == xr)
			zw = i + 1;
	}
	c = zw % m;
	if (zw / m % 2 == 0)
		r = 1;
	else
		r = m;
	cout << c << ' ' << r;
	return 0;
}
