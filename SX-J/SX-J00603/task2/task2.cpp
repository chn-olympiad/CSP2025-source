#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[10][10];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	const int t = a[0];
	for (int i = 0; i < n * m - 1; i++) {
		for (int j = 0; j < n * m - 1; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				b[j][i] = a[ i * n + j];
			}
		} else {
			for (int j = n - 1; j >= 0; j--) {
				b[j][i] = a[(i + 1) * n - j - 1 ];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == t) {
				cout << j + 1 << " " << i + 1;
				return 0;
			}
		}
	}
}