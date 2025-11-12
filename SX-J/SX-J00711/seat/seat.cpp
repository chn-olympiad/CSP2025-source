#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int xr = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= m + 1; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				if (a[(i - 1) * n + j] == xr) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j > 0; j--) {
				if (a[(i - 1) * n + (m + 1 - j)] == xr) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
