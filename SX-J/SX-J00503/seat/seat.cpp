#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[105] = {};
	int b[15][15] = {};
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m ; i++) {
		if (a[i] < a[i + 1 ] ) {
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 1; i <= m ; i++) {
		for (int j = 1; j <= n  ; j++) {
			if (j % 2 == 0) {
				for (int t = m; t >= 1 ; t--) {

					a[t] = b[t][j];
				}
			} else {
				a[i] = b[i][j];

			}
		}
	}
	for (int i = 1; i <= m ; i++) {
		for (int j = 1; j <= n  ; i++) {
			if (b[i][j] == a[1]) {
				cout << b[i][j];
			}
		}
	}
	return 0;
}