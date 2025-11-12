#include <bits/stdc++.h>
using namespace std;
int n, m, ap[100000], t;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> ap[i];
	}
	t = ap[1];
	sort(ap + 1, ap + 1 + m *n);
	for (int x = n * m; x >= 1 ; x--) {
		int l = m * n + 1 - x;
		if (ap[x] == t) {
			if (l % n == 0) {
				cout << l / n << " " ;
				if ((l / n) % 2 == 1) {
					cout << n;
				} else {
					cout << 1;
				}

			} else if (l % n != 0) {
				cout << l / n + 1 << " " ;
				if ((l / n + 1) % 2 == 1)
					cout << l % n ;
				else {
					cout << n - l % n + 1;
				}
			}
			break;
		}
	}
	return 0;
}
