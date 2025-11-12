#include <bits/stdc++.h>
using namespace std;
int m, n, a[105], k, x = 1;

bool cmp(int p, int q) {
	return q < p;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= m; j++) {
				if (a[x] == k) {
					cout << i << " " << j << "\n";
					return 0;
				} else {
					x++;
				}
			}
		} else if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				if (a[x] == k) {
					cout << i << " " << j << "\n";
					return 0;
				} else {
					x++;
				}
			}
		}
	}
}