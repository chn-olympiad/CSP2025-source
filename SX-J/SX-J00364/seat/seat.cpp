#include <bits/stdc++.h>
using namespace std;
int n, m,  kr, maxx = -1, x = 1, xx = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a[n][m];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	kr = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > maxx) {
				maxx = a[i][j];
				a[i][j] = -2;
			}
		}
	}
	if (kr == maxx) {
		cout << 1 << ' ' << 1;
		return 0;
	}
	x = 1, xx = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			maxx = -1;
			maxx = max(maxx, a[i][j]);
			if (i == 1 && j == 1) {
				a[i][j] = -2;
				continue;
			}
			a[i - 1][j - 1] = -2;
			if (a[x][xx] != maxx && xx >= m && x % 2 == 1) {
				xx = m, x++;
			}
			if (a[x][xx] != maxx && xx != 1 && x % 2 == 0) {
				xx--;
			}
			if (a[x][xx] != maxx && xx == 1 && x % 2 == 0) {
				xx = 1;
				x++;
			}
			if (a[x][xx] == maxx) {
				cout << x << ' ' << xx;
				return 0;
			}
			xx++;
		}
	}
	cout << x << ' ' << xx;
	return 0;
}
