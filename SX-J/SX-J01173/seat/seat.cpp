#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, a[110];
	cin >> n >> m;
	int w = n * m;
	int R, k, c, r;
	for (int i = 0; i < w; i++) {
		cin >> a[i];
		R = a[0];
		if (a[i] > a[i - 1]) {
			swap(a[i], a[i - 1]);
		}
	}
	for (int i = 0; i < w; i++) {
		if (a[i] == R) {
			k = i;
			break;
		}
	}
	if (k <= n) {
		r = n - (n % k);
		c = 1;
	} else if (k > n && k <= 2 * n) {
		r = n - (n % (k - n)) - 1;
		c = 2;
	}
	cout << c << " " << r;
	return 0;
}
