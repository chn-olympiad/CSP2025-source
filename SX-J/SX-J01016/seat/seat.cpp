#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen(seat.in, "r", stdin);
	freopen(seat.out, "w", stdout);
	int n, m, c, x = 1, y = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	int sum = a[1];
	for (int i = 1; i <= n * m; ++i) {
		for (int j = 1; j <= n * m; ++j) {
			if (a[i] < a[j + 1]) {
				c = a[i];
				a[i] = a[j + 1];
				a[j + 1] = c;
				break;
			}
		}
	}
	for (int i = 1; i <= n * m; ++i) {

		if (x % 2 == 0) {
			if (a[x + y] == sum) {
				cout << x << " " << y;
				break;
			}
			y--;
		}

		if (x % 2 != 0) {
			if (a[i] == sum) {
				cout << x << " " << y;
				break;
			}
			y++;
		}

		if (y == 1) {
			if (a[i] == sum) {
				cout << x << " " << y;
				break;
			}
			x++;
			y = 0;
		}
		if (y == n) {
			if (a[i] == sum) {
				cout << x << " " << y;
				break;
			}
			x++;
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
