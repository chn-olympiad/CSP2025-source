#include <bits/stdc++.h>
using namespace std;
int seat[11][11];
int m, n, flag;
int y, o = 0;
int b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	o = m * n;
	for (int i = 1; i <= o; i++) {
		cin >> b[i];
		if (i == 1) {
			flag = b[1];
		}
	}
	sort(b + 1, b + o + 1);
	o += 1;
	for (int x = 1; x <= m; x++) {
		if (x % 2 != 0) {
			for (y = 1; y <= n; y++) {
				o--;
				if (b[o] == flag) {
					cout << x << " " << y;
					return 0;
				}
			}

		} else {
			for (y = n; y >= 1; y--) {
				o--;
				if (b[o] == flag) {
					cout << x << " " << y;
					return 0;
				}
			}
		}
	}
	return 0;
}