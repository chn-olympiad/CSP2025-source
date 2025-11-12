#include <bits/stdc++.h>
using namespace std;

bool cmd(int z, int x) {
	return z > x;
}


int a[105] = {};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int f;
	int n, m;
	cin >> n >> m;
	for (int q = 1; q <= n * m; q++) {
		if (q == 1) {
			cin >> f;
			a[1] = f;
		} else
			cin >> a[q];
	}
	int sum = 1;
	sort(a + 1, n *m + a + 1, cmd);
	for (int q = 1; q <= n; q++) {
		if (q % 2 == 1) {
			for (int w = 1; w <= m; w++) {
				if (a[sum] == f) {
					cout << q << " " << w;
					return 0;
				}
				sum++;
			}
		} else {
			for (int e = m; e > 0; e--) {
				if (a[sum] == f) {
					cout << q << " " << e;
					return 0;
				}
				sum++;
			}
		}

	}
	return 0;
}