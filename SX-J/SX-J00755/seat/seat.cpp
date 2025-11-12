#include <bits/stdc++.h>
using namespace std;
int n, m, a[10000], x, maxx = -1, l = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		a[1] = x;
		if (a[i] > a[i + 1]) {
			a[i] = a[i];
		} else if (a[i] < a[i + 1]) {
			a[i] = a[i + 1];
		} else {
			a[i] = a[i];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (x == a[j]) {
				if (i % 2 != 0) {
					cout << j << " " << i + x;
					break;
				} else if (i % 2 == 0) {
					cout << j << " " << i - x;
				}
			}
		}
	}
	return 0;
}
