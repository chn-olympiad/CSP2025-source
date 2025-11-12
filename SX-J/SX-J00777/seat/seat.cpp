#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, i, j, sum;
	cin >> n >> m;
	k = n * m;
	for (i = 1; i <= k; i++) {
		cin >> a[i];
	}
	sum = a[1];
	sort(a + 1, a + k + 1);
	for (j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (i = 1; i <= n; i++) {
				b[i][j] = a[k--];
			}
		} else {
			for (i = n; i >= 1; i-- ) {
				b[i][j] = a[k--];
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (b[i][j] == sum)
				cout << j << ' ' << i;
		}
	}
	return 0;
}
