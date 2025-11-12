#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, x, sum;
int a[200];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		if (a[i] > a[0]) {
			sum++;
		}
	}
	sum++;
	if (sum % n == 0) {
		c = sum / n;
	} else {
		c = sum / n + 1;
	}
	cout << c << " ";
	if (c % 2 == 0) {
		if (sum % n == 0) {
			r = 2 * (sum % n) + 1;
		} else {
			r = sum % n + 1;
		}
	} else {
		r = sum % (2 * n);
	}
	cout << r;
	return 0;
}
