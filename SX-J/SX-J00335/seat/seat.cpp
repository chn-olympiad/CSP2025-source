#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[110];
int zw[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	int xm = a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1);
	int hm = 1;
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == xm) {
			break;
		}
		hm++;
	}
	int zshm = 1;
	int x = 1, y = 1;
	for (int i = 1; i <= m; i++) {
		if (x % 2 == 1) {
			for (int j = 0; j < n; j++) {
				zw[x][y] = zshm;
				zshm++;
				y++;
			}
			y -= 1;
		} else {
			for (int j = 0; j < n; j++) {
				zw[x][y] = zshm;
				zshm++;
				y--;
			}
			y += 1;
		}
		x++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (zw[j][i] == hm) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
