#include <bits/stdc++.h>

using namespace std;

int a[110], b[110], r, m, n;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	r = a[1];
	sort(b + 1, b + 1 + n *m);
	for (int i = 1; i <= n * m; i++) {
		a[i] = b[n * m - i + 1];
	}
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << " ";
//	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
//			cout << a[i] << " " << i << " ";
			if ((i / n) % 2 == 0) {
				if (i % n == 0) {
					cout << i / n << " " << 1;
				} else {
					cout << i / n + 1 << " " << i % n;
				}
			}
			if ((i / n) % 2 != 0) {
				if (i % n == 0) {
					cout << i / n << " " << n;
				} else {
					cout << i / n + 1 << " " << n - i % n + 1;
				}
			}
		}
	}
	return 0;
}
