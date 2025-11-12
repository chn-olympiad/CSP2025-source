#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m;
	int r;
	int w;
	int c, u;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		w = a[1];
	}
	sort(a, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == w) {
			r = n * m - i + 1;
			break;
		}
	}
	cout << r << endl;
	if (((r / m) + 1) % 2 == 1 && r > n) {
		cout << "a" << endl;
		if (r % m != 0) {
			c = r / m + 1;
		}
		if (r % m == 0) {
			c = r / m;
		}
		u = r % n;
	}
	if (((r / m) + 1) % 2 == 0 && r > n) {
		cout << "b" << endl;
		if (r % m != 0) {
			c = r / m + 1;
		}
		if (r % m == 0) {
			c = r / m;
		}
		u = m - (r % n) + 1 ;
	}
	if (r <= n) {
		c = 1;
		u = r;
	}
	cout << c << " " << u;
	return 0;
}
