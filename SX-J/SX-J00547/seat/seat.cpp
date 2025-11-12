#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], hantata, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > a[i - 1][j - 1]) {
				a[i - 1][j - 1] = a[i][j];
			}
			if (i > m) {
				i = n + 1;
			}
			c = n;
			m = r;
		}
	}
	cout << c << " " << r;
	return 0;
}