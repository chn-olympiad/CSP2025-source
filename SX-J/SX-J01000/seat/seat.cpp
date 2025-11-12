#include <bits/stdc++.h>
using namespace std;
int a[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int me = a[0][0];
	if (me == 100) {
		cout << 1 << " " << 1;
		return 0;
	}
	int x = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > me) {
				x++;
			}
		}
	}
	int l = x / m ;
	l += 1;
	x = x % m;
	if (l % 2 == 1) {
		cout << l << " " << x;
		return 0;
	}
	if (l % 2 == 0) {
		cout << l << " " << m  - x;
		return 0;
	}
	return 0;
}

