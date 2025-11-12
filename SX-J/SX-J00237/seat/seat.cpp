#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[105], a1, r;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int xz[11][11], cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			xz[j][i] = a[++cnt];
		}
	}
	for (int i = 2; i <= m; i += 2) {
		for (int j = 1; j <= n / 2; j++) {
			swap(xz[j][i], xz[n - j + 1][i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (xz[i][j] == a1) {
				cout << j << ' ' << i;
			}
		}
	}

	return 0;
}
