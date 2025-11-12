#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, b[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		x = a[1];
		sort(a, a + n *m + 1);
		for (int k = n; k >= 1; k--) {
			for (int j = m; j >= 1 ; j--) {
				if (b[i][j] == x) {
					cout << j << " " << k;
					return 0;
				}
			}
		}
	}
	return 0;
}
