#include <bits/stdc++.h>
using namespace std;
int o[11][11];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt, x;

	int a[101];
	cin >> n >> m;
	cnt = m * n;
	int y = cnt - 1;
	for (int k = 0; k < cnt; k++) {
		cin >> a[k];
	}
	x = a[0];
	sort(a, a + cnt);
	for (int i = 1; i <= m; i++) {
		int j = 1;
		int u = n;
		while (j <= n && u >= 1) {
			if (i % 2 == 1) {
				o[i][j] = a[y];
				y--;
				j++;
			}
			if (i % 2 == 0) {
				o[i][u] = a[y];
				y--;
				u--;
			}
		}
	}
	for (int t = 1; t <= m; t++) {
		for (int q = 1 ; q <= n; q++) {
			if (o[t][q] == x) {
				cout << t << ' ' << q;
			}
		}
	}
	return 0;
}