#include <bits/stdc++.h>
using namespace std;
long long a[105], x, y, n, m, b;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n;
	cin >> m;
	a[0] = INT_MAX;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b = a[1];
	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m; j++) {
			if (a[i] > a[i - 1])
				swap(a[i], a[i - 1]);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b) {
			if (i <= n) {
				cout << 1 << " " << i;
				return 0;
			}

			for (int j = 2; j <= m; j++) {
				if (i <= n * j) {
					if (j % 2 == 1) {
						cout << j << " " << i - n*(j - 1);
						return 0;
					}
					if (j % 2 == 0) {
						cout << j << " " << n - (i - (j - 1)*n) + 1;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
