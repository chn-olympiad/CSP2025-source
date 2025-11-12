#include <bits/stdc++.h>
using namespace std;
int p[1000], xy[100][100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		int a;
		cin >> a;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	for (int z = 0; z < n * m; z++) {
		cin >> p[z];
	}
	int hm = p[0];
	sort(p, p + n *m);
	int nm = n * m, lj = n * m - 1, fx = 1, x = 1, y = 1;
	while (nm > 0) {
		if (fx == 1 && x < n) {
			xy[x][y] = p[lj];
			lj--;
			nm--;
			x++;
			if (x == n) {
				fx = 2;
			}
		} else if (fx == 2) {
			xy[x][y] = p[lj];
			lj--;
			nm--;
			y++;
			if (x == n) {
				fx = 3;
			} else {
				fx = 1;
			}
		} else if (fx == 3 && x > 1) {
			xy[x][y] = p[lj];
			lj--;
			nm--;
			x--;
			if (x == 1) {
				fx = 2;
			}
		}
	}
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			if (xy[q][w] == hm) {
				cout << w << " " << q << endl;
			}
		}
	}
	return 0;
}