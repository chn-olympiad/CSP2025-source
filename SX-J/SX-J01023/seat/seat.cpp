#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = n * m;
	int a[c + 1];
	int d[n + 1][m + 1];
	int h[c + 1];
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	int x = a[1];
	sort(a, a + c + 2);
	for (int i = 1; i <= c; i++) {
		h[i] = a[c - i + 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 != 0) {
				d[j][i] = h[(i - 1) * n + j];
			} else {
				d[j][i] = h[i * n - (j - 1)];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x == d[i][j]) {
				cout << j << " " << i << endl;
			}
		}
	}
	return 0;
}