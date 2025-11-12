#include <bits/stdc++.h>
using namespace std;
int a[110], b[20][20];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	long long n, m, c, d = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	c = a[1];
	for (int i = n * m; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (a[j] <= a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			d = d + 1;
			if (i % 2 == 0) {
				b[i][n + 1 - j] = a[d];
			} else {
				b[i][j] = a[d];
			}
			if (b[i][j] == c) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}