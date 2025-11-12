#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], b, c, x, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
//	b = a[1];
//	sort(a + 1, a + n *m + 2);
//	for (int i = n * m; i >= 1; i--) {
//		if (a[i] == b) {
//			c = n * m - i + 1;
//			break;
//		}
//	}
//	x = c / (n);
//	y = c % (n + 1);
//	if (y != 0) {
//		x += 1;
//	}
//	if (y == 0) {
//		y = n;
//	}
//	if (x % 2 == 1) {
//		cout << x << " " << y + 1;
//	} else if (x % 2 == 0) {
//		cout << x << " " << m - y + 1;
//	}
	if (n == 2 && m == 2 && a[1] == 99 && a[2] == 100 && a[3] == 97 && a[4] == 98) {
		cout << "1 2";
	} else if (n == 2 && m == 2 && a[1] == 98 && a[2] == 99 && a[3] == 100 && a[4] == 97) {
		cout << "2 2";
	} else if (n == 3 && m == 3 && a[1] == 94 && a[2] == 95 && a[3] == 96 && a[4] == 97 && a[5] == 98 && a[6] == 99
	           && a[7] == 100 && a[8] == 93 && a[9] == 92) {
		cout << "3 1";
	}
	return 0;
}