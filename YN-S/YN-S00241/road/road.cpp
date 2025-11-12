#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans = 0;
long long a[10005][3];
long long c[10][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}

	long long q;

	for (int i = 1; i <= k; i++) {

		cin >> q;

		for (int j = 1; j <= n; j++) {

			cin >> c[i][j];
		}

		for (int j = 1; j <= n; j++) {

			for (int k = j; k <= n; k++) {

				if (j != k) {
					m++;
					a[m][1] = j;
					a[m][2] = k;
					a[m][3] = q + c[i][j] + c[i][k];
				}

			}
		}
	}

	int d = 0;

	while (d <= n - 2) {
		d++;
		bool k = 1;
		long long x = 999999999, y;

		for (int i = 1; i <= m; i++) {

			if (x > a[i][3]) {
				x = a[i][3];
				y = i;
			}
		}
		ans += a[y][3];
		a[y][3] = 999999999;
	}

	cout << ans;

	return 0;
}
