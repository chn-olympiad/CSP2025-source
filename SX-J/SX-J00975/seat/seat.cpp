#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int m, n, a[110], a1, c, r, x;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a1 == a[i]) {
			x = i;
			break;
		}
	}
	if (x % n == 0) {
		c = x / n;
	} else {
		c = x / n + 1;
	}
	if (c % 2 == 0) {
		r = n + 1 - x % n;
	} else {
		if (x % n != 0) {
			r = x % n;
		} else {
			r = n;
		}
	}
	cout << c << " " << r;

	return 0;
	fclose(stdin);
	fclose(stdout);
}