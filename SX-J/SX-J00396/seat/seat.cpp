#include <bits/stdc++.h>
using namespace std;
int a[100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, z, j = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int x = a[1];
	for (int i = 1; i <= n * m; i++) {
		if (a[i] < a[i + 1]) {
			c = a[i];
			a[i] = a[i + 1];
			a[i + 1] = c;
		}
		if (a[i] > a[i - 1] && i > 1) {
			c = a[i - 1];
			a[i - 1] = a[i];
			a[i] = c;
		}
	}
	for (int i = 1; i <= n * m; i++) {
		z = i / m;
		x++;
		if (a[i] == x) {
			if (i == n) {
				cout << 1 << " " << n;
				return 0;
			} else if (i = j * n + 1) {
				cout << n + 1 << " " << 1;
				return 0;
			} else if (i = n + 1) {
				cout << m << " " << n + m / 2;
				return 0;
			} else if (i % m != 0) {
				if (z % 2 == 0) {
					cout << z << " " << n - i / n;
					return 0;
				} else if (z % 2 != 0) {
					cout << m + 1  << " " << i / n;
					return 0;
				}
			} else if (m % 2 != 0) {
				if (i == n * m) {
					cout << m << " " << n;
				}
			}
		}
	}
	return 0;
}
