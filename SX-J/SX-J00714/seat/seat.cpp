#include <bits/stdc++.h>
using namespace std;
long long	 n, m, a[105], b[105], t, c[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	t = n * m;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + t);

	for (int j = 1; j <= m; j++) {
		if (j % 2 == 0) {
			for (int k = n; k >= 1; k--) {
				c[j][k] = b[t];
				t--;
			}

		} else {
			for (int i = 1; i <= n; i++) {
				c[j][i] = b[t];
				t--;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[1] == c[i][j])
				cout << i << " " << j;
		}
	}
	return 0;
}
