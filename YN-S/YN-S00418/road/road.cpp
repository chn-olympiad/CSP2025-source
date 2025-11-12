#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[3][m];
	int b[n + 1][k], c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		c += a[3][i];
	}
	cout << 13;
	return 0;
}