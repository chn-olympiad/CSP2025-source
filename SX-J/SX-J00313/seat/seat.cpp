#include <bits/stdc++.h>
using namespace std;
int a[105];
int m, n, sum = 0;
int r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	a[r]++;
	for (int i = 1; i < n * m; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 100; i >= r; i--) {
		sum += a[i];
	}
	if (sum % n == 0) {
		cout << sum / n;
	} else {
		int x = sum / n;
		x++;
		cout << x;
	}
	int x = 2 *  n;
	x = sum % x;
	if (x <= n && x > 0) {
		cout << " " << x;
	} else if (x > n) {
		cout << " " << 2 * n - x + 1;
	} else {
		cout << " " << 1;
	}
	return 0;
}
