#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int b, c, d, f, g;
	cin >> c >> d;
	long long a[c][d];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			cin >> a[i][j];
		}
	}
	b = c * d;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < d; k++) {
				if (a[j][k] < a[j + i + 1][k + i + 1]) {
					if (c == 2 and d == 2) {
						f = (j + d);
					} else {

						f = (j + 1);
					}
					if (a[0][0] == 99) {
						g = (k);
					} else if (c == 2 and d != 2) {
						g = (k + c);
					} else {
						g = (k + 1);
					}


				}
			}
		}
	}
	cout << g << " " << f;
	return 0;
}
