#include <bits/stdc++.h>
using namespace std;

int n, m, a[110], r, c[15][15];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m >> r;

	for (int i = 1 ; i < n * m ; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + (n *m) + 1, cmp);
	int t = 1;
	for (int j = 1 ; j <= m ; j++) {
		if (j % 2 != 0) {
			for (int i = 1 ; i <= n ; i++) {
				if (r > a[t]) {
					cout << j  << " " << i;
					return 0;
				}
				c[i][j] = a[t];
				t++;
			}
		} else {
			for (int i = n ; i >= 1 ; i--) {
				if (r > a[t]) {
					cout << j  << " " << i;
					return 0;
				}
				c[i][j] = a[t];
				t++;
			}
		}
	}
	return 0;
}
