#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int b[225];

int main() {
	freopen("seat.in", "r", "stdin");
	freopen("seat.out", "w", "stdout");
	long long i, r = 0, m, n, j, e = 0, f = 0, z = 0;
	cin >> n >> m;
	int d = n * m;
	for (i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	r = b[1];
	sort(b + 0, b + (n *m ) + 1);
//	cout << b[1] << " " << b[2] << " " << b[3] << " " << b[4];
	for (i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (j = 1; j <= n; j++) {
				a[j][i] = b[d];
				d--;
			}
		}
		continue;
		if (i % 2 == 0) {
			for (j = n; j >= 1; j--) {
				a[j][i] = b[d];
				d--;
			}
		}
	}
	for (i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (j = 1; j <= n; j++) {
				z++;
				if (a[j][i] == r)
					f = n / z - n % z ;
				e = z / m + z % m;
				cout << f + 1 << " " <<  e + 1;
				return 0;
			}
		}
		continue;
		if (i % 2 == 0) {
			for (j = n; j >= 1; j--) {
				z++;
				if (a[j][i] == r)
					f = z / n + z % n;
				e = z / m + z % m;
				cout << f + 1 << " " << e + 1;
				return 0;
			}
		}
	}
	return 0;
}
