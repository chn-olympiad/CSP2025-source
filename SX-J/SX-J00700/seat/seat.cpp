#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[50][50], b[110];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s = 1;
	cin >> m >> n;
	int w = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			b[w] = a[i][j];
			w++;
		}
	}
	int nm = n * m;
	int r = b[1];
	sort(b + 1, b + 1 + nm);
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == r) {
			r = n * m - i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s == r) {
				cout << i  << " " << j;
				return 0;
			}
			if (i % 2 == 1) {
				if (j == m && a[i + 1][j] != 0) {
					i++;
					s++;
				} else {
					j++;
					s++;
				}
			} else {
				if (j == 1 && a[i + 1][j] != 0) {
					i++;
					s++;
				} else {
					j--;
					s++;
				}
			}
		}
	}
	return 0;
}
