#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, y[100] = {}, o = 0, k = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> y[i];
		o = y[1];
		k = i;
	}
	sort(y, y + k);
	for (int u = 1; u <=  n * m; u++) {
		if (y[u] == o) {
			if (u <=  m) {
				n = u % m;
				cout << n + 1 << "  " << u - 1;
			} else {
				n = u / m + 1;
				m = u - m;
				cout << n << "  " << m;
			}

		}
	}
	return 0;
}
