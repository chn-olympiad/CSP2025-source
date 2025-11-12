#include <bits/stdc++.h>
using namespace std;
int t, n, a[10010][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t >> n;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int h = 1; h <= n; h++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= 3; y++) {
					cin >> a[x][y];
				}
			}
			if (n == 2) {
				int x = max(a[1][1], a[1][2]);
				int x1 = max(x, a[1][3]);
				int x2;
				if (x1 == a[1][1]) {
					x2 = 1;
				} else if (x1 == a[1][2]) {
					x2 = 2;
				} else if (x1 == a[1][3]) {
					x2 = 3;
				}


				int y = max(a[2][1], a[1][2]);
				int y1 = max(y, a[2][3]);
				int y2;
				if (y1 == a[2][1]) {
					y2 = 1;
				} else if (x1 == a[2][2]) {
					y2 = 2;
				} else if (x1 == a[2][3]) {
					y2 = 3;
				}


				if (x2 != y2) {
					cout << x1 + y1 << endl;
				} else {
					if (x1 >= y1) {
						cout << x1 + y << endl;
					} else {
						cout << y1 + x << endl;
					}
				}
			}
		}
	}
	return 0;
}
