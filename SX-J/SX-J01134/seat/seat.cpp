#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int R = a[0];
	sort(a, a + n *m);
	for (int i = 0; i < n * m; i++) {
		if (a[i] == R) {
			R = n * m - i;
			break;
		}
	}
	if (R > n) {
		if (R % n == 0) {
			x = R / n;
			cout << x << ' ';
			if (x % 2 == 1) {
				cout << n;
			} else {
				cout << 1;
			}
		} else {
			x = R / n + 1;
			cout << x << ' ';
			if (x % 2 == 1) {
				cout << R % n;
			} else {
				cout << n - R % n + 1;
			}
		}
	} else {
		cout << 1 << ' ' << R;
	}
	return 0;
}
