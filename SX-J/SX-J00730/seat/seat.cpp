#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], maxx = INT_MIN, y, s;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
		for (int j = 1; j <= x; j++) {
			if (a[i] > maxx) {
				maxx = a[i];
				s = j;
				y++;
			}
		}
		if (s = 1) {
			if (y = 1) {
				cout << "1 1";
			} else {
				if (y % n == 0) {
					if (y / n % 2 != 0) {
						cout << y / n << " " << n;
					} else {
						cout << y / n << " 1";
					}
				} else if (y % n == 1 && (y - 1) / n % 2 == 0) {
					cout << (y - 1) / n + 1 << " " << n;
				} else {
					cout << y / n  << " " << (y - y / n) / m;
				}
			}
		}
	}
	return 0;
}
