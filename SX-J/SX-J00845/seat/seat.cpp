#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[115];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long p = a[1], l = 1;
	for (int i = 2; i <= n * m; i++) {
		if (p < a[i]) {
			l++;
		}
	}
	long long x, y, o;
	if (l % n == 0) {
		x = l / n;
		if (x % 2 == 0) {
			y = 1;
		} else {
			y = n;
		}
	} else {
		x = l / n + 1;
		o = l % n;
		if (x % 2 == 0) {
			y = n - o + 1;
		} else {
			y = 1 + o - 1;
		}
	}
	cout << x << ' ' << y;
	return 0;
}