#include <bits/stdc++.h>
using namespace std;
long long n, m, r, a[110], b[20][20];

bool cmp(int a1, int b1) {
	return a1 > b1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	a[1] = r;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	long long  id = 0, x = 1, y = 1, c = 1;
	while (true) {
		if (y == m + 1) {
			break;
		}
		id++;
		b[x][y] = a[id];
		x = x + c;
		if (x == n + 1) {
			c = -1;
			x--;
			y++;
		}
		if (x == 0) {
			c = 1;
			x++;
			y++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == r) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
