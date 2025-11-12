#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[105];
int b[102][102];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + m *n + 1);
	int sum = m * n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				b[j][i] = a[sum];
				sum--;
			}
		}
		if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				b[j][i] = a[sum];
				sum--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == r) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}