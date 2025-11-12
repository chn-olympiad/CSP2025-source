#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a, s;
	cin >> n >> m;
	int su = n * m;
	int num[n * m + 1], ans[n][m];

	while (su > 0) {
		cin >> a;
		s = a;
		su--;
		continue;
	}

	for (int i = 1; i <= su; i++) {
		num[i] = a;
	}

	sort(num + 1, num + n *m + 1);
	for (int j = 1; j <= n; j++ ) {
		for (int i = 1; i <= m; i++) {
			for (int x = n * m; x >= 1; x--) {
				ans[j][i] = num[x];
			}
			if (ans[i][j] == s && j % 2 != 0) {
				cout << i + 1 << " " << j + 1;
				return 0;
			} else {
				cout << j << " " << i + 1 ;
				return 0;
			}
		}
	}
	return 0;
}