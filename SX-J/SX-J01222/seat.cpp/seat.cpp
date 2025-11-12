#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int c, r = 1;
	int q = a[1];
	for (int i = 1; i <= n * m; i++) {
		if (c % 2 == 0) {
			if (a[i] > q && r > 1) {
				r --;
			} else {
				c ++;
				r = 1;
			}
		} else {
			if (a[i] > q && r < n) {
				r ++;
			} else {
				c ++;
				r = n;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}