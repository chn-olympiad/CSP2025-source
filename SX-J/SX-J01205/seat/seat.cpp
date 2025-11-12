#include <bits/stdc++.h>
using namespace std;
int a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, b = 1, d, c, zui = 0;
	cin >> n >> m;
	while (b <= n * m) {
		cin >> c;
		a[c] = c;
		d = c;
		b++;
		if (c > zui)
			zui = c;
	}
	c = 0;
	b = 1;
	for (int j = zui; j > 0; j--) {
		if (c == n) {
			c = 0;
			b++;
		}
		if (a[j] != 0) {
			c++;
		}
		if (a[j] == d) {
			cout << c << " " << b;
			return 0;
		}
	}
	return 0;
}
