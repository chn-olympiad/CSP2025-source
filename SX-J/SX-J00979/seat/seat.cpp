#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[15][15];
int c, r, mx;
int d = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 1 && m <= 1) {
		cout << a[1];
	} else {
		for (int i = 1; i <= n * m; i++) {
			if (d % 2 == 0) {
				r++;
			} else {
				r--;
			}
			b[c][r] = a[i];
			if (b[c][r] == a[1]) {
				cout << c << " " << r;
			}
			if (r % m == 0) {
				d++;
			}

		}
		return 0;
	}
}
