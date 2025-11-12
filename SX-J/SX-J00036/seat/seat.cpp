#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], b, h, k, s = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	b = a[1];
	sort(a, a + n *m + 1);
	for (int i = n * m ; i >= 1; i--, s++) {
		if (a[i] == b) {
			if (s > n) {
				h = s % n;
				k = (s - h) / m;
				if (h != 0) {
					cout << k + 1 << ' ' << h;
				} else {
					cout << m << ' ' << n;
				}
			} else {
				cout << 1 << ' ' << s;
			}
		}
	}
	return 0;
}