#include <bits/stdc++.h>
using namespace std;
int a[110];
int m, n, js = 0, r, wz = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[js];
			if (a[js] > a[0]) {
				wz++;
			}
			js++;

		}
	}
	if (wz % m == 0) {
		cout << wz / m << " ";
		if ((wz / m) % 2 != 0) {
			cout << m;
		} else {
			cout << 1;
		}
	} else {
		cout << wz / m + 1 << " ";
		if ((wz / m) % 2 != 0) {
			cout << m - wz % m + 1;
		} else {
			cout << wz % m;
		}
	}
	return 0;
}
