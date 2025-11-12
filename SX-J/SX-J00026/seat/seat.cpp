#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], R, zal, maxx = INT_MIN, b[15][15], y = 1, z = 1;

int main() {
	freopen("seat in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	zal = n * m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	R = a[1][1];
	while (zal--) {
		maxx = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				maxx = max(maxx, a[i][j]);
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (maxx == a[i][j]) {
					a[i][j] = 0;
				}
			}
		}
		if (z == n) {
			b[y][z] = maxx;
			z = 1;
			y++;
		} else {
			b[y][z] = maxx;
			z++;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (R == b[i][j]) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
