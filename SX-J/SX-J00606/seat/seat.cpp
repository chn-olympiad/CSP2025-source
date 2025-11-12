#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], b[105], c;
int d, e;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	c = a[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m; j++) {
			if (b[i] < a[j]) {
				b[i] = a[j];
			}
		}
		for (int j = 1; j <= n * m; j++) {
			if (b[i] == a[j]) {
				a[j] = 0;
			}
		}
		if (b[i] == c) {
			c = i;
			break;
		}
	}
	if (c % n == 0) {
		d = c / n;
	} else {
		d = c / n + 1;
	}
	if (d % 2 != 0 && c % n == 0) {
		e = c % n + 2;
	} else if (d % 2 != 0) {
		e = c % n;
	} else if (d % 2 == 0 && c % n == 0) {
		e = 1;
	} else if (d % 2 == 0) {
		e = n - (c % n);
	}
	cout << d << " " << e;
	return 0;
}
