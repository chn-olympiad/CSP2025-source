#include <bits/stdc++.h>
using namespace std;
int h, l, b, c, d;
int a[1005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> h >> l;
	for (int i = 1; i <= h * l; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[0] > a[i]) {
				cout << "1 1";
			}
			if (a[0] < a[i]) {
				b++;
			}

			if (b > 2 and b - 2 >= 1 and b % h >= 1 and b / h > 1) {
				c++;
				d = h - h / b;
				cout << c << " " << d;
			} else {
				if (b <= 2) {
					cout << "1" << " " << "2";
				}
			}
		}
	}
	return 0;
}