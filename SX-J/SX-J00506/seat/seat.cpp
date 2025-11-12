#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		cnt++;
		if (a[i] == x) {
			break;
		}
	}
	int y = ceil(1.0 * cnt / m);
	if (y % 2 == 1) {
		if (cnt % m == 0) {
			cout << y << ' ' << m;
		} else {
			cout << y << ' ' << cnt - (cnt / m *n);
		}
	} else {
		if (cnt % m == 0) {
			cout << y << ' ' << 1;
		} else {
			cout << y << ' ' << m - (cnt - (cnt / m *n)) + 1;
		}
	}
	return 0;

}
