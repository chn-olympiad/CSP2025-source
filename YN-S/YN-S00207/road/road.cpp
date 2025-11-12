#include <bits/stdc++.h>
using namespace std;
int n, m, k, d = 0, z = 0, t = 0, b = 0, s = 0;
int c[10005][10005], a[10005][10005], p[10005], x[10005], y[10005];


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (c[i][3] <= c[i + 1][3]) {
				p[i] = c[i][3];
			}
			cout << p[i] << endl;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (a[i][1] <= a[i + 1][1]) {
				y[i] = a[i][1];
			}
			if (a[1][j + 1] <= a[1][j + 2]) {
				x[j] = a[1][j];
			}
			cout << y[i] << ' ' << x[j] << endl;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			while (x[j] > p[i]) {
				d += x[j];
				n--;
				b++;
			}
		}
	}
	for (int i = 1; i <= b ; ++i) {
		z += y[i];
	}
	for (int i = 1; i <= n / 2; ++i) {
		s += p[i];
	}
	t = s + z + d;
	cout << t;
	return 0;
}
