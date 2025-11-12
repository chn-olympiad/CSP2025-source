#include <bits/stdc++.h>
using namespace std;
long long n, m, p, cj, x, y;
int a[500];

int cmp(int l, int r) {
	return l > r;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	cj = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == cj) {
			p = i;
			break;
		}
	}
	if (p % n == 0) {
		x = p / n;
	} else {
		x = p / n + 1;
	}
	if (x % 2 == 0) {
		if (p % n == 0) {
			y = 1;
		} else {
			y = n + 1 - (p % n);
		}
	} else {
		if (p % n == 0) {
			y = n;
		} else {
			y = p % n;
		}
	}
	cout << x << ' ' << y;
	return 0;
}
