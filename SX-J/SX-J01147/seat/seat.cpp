#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	short n, m, ax, a1, x = 1, a = 1, b = 1;
	cin >> n >> m >> a1;
	for (short i = 1; i < n * m; i++) {
		cin >> ax;
		if (ax > a1)
			x++;
	}
	for (int i = 1; i < x; i++) {
		if (a % 2) {
			if (b == n)
				a++;
			else
				b++;
		} else {
			if (b == 1)
				a++;
			else
				b--;
		}
	}
	cout << a << " " << b;
	return 0;
}