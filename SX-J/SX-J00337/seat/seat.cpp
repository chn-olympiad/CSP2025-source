#include <bits/stdc++.h>
using namespace std;
int m, n, a[1005], t, cnt;

bool c(int n_1, int n_2) {
	if (n_1 >= n_2) {
		return true;
	}
	if (n_1 < n_2) {
		return false;
	}
	return true;
}
int j;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n *m + 1, c);
	for (int i = 1; i <= n * m; i++) {
		if (t == a[i]) {
			j = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int k = 1; k <= n; k++) {
				cnt++;
				if (cnt == j) {
					cout << i << " " << k;
					return 0;
				}
			}
		}
		if (i % 2 == 0) {
			for (int k = n; k >= 1; k--) {
				cnt++;
				if (cnt == j) {
					cout << i << " " << k;
					return 0;
				}
			}
		}
	}
	return 0;
}