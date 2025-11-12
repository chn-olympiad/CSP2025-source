#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, c, r;
	int a[15][15];
	int c[105];
	int d[5];
	cin >> n >> m;
	for (int x = 1; x <= m * n; x++) {
		cin >> c;
		d[x] = c[1];
		if (c[x] < c[x + 1]) {
			c[x] = c[x + 1];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (x / n % 2 == 1)
					a[i][j] = a[n - 7 / n * n][j + 1];
				if (x / n % 2 == 0)
					a[i][j] = a[7 / n * n][j + 1];
			}
		}

	}
	cout << a;
	return 0;
}