#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 10];
long long b[100000 + 10];
long long e[100000 + 10];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, x;
	cin >> n >> m;
	for (long long i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	long long maxx = -1, cnts = 0, y = n * m, z, h = 1;
	while (y) {
		for (long long i = 1; i <= n * m; i++) {
			if (a[i] > maxx) {
				maxx = a[i];
				z = i;
			}
		}
		if (maxx == x && z == 1) {
			cnts = h;
		}
		b[h] = maxx;
		a[z] = -1;
		maxx = -1;
		y--;
		h++;
	}
	long long c, d, f = 1;
	c = cnts / m;
	d = cnts % m;
	if (d == 0) {
		if (c % 2 == 0) {
			for (long long i = m; i >= 1; i--) {
				e[f] = i;
				f++;
			}
			cout << c << " " << 1;
		} else {
			for (long long i = 1; i <= m; i++) {
				e[f] = i;
				f++;
			}
			cout << c << " " << m;
		}
	} else {
		if ((c + 1) % 2 == 0) {
			for (long long i = m; i >= 1; i--) {
				e[f] = i;
				f++;
			}
			cout << c + 1 << " " << e[d];
		} else {
			for (long long i = 1; i <= m; i++) {
				e[f] = i;
				f++;
			}
			cout << c + 1 << " " << e[d];
		}
	}
	return 0;
}
