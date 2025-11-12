#include <bits/stdc++.h>
using namespace std;
long long n = 3, m = 2, temp, a2, a2n, nx, mx;
long long a[110], b[20][20], a1[110];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a2 = a[1];
	sort(a, a + (n *m));
	temp = n * m - 1;
	for (int i = 1; i <= n * m; i++) {
		a1[i] = a[temp];
		temp--;
	}
	for (int i = 1; i <= n * m; i++) {
		if (a1[i] == a2) {
			a2n = i;
		}
	}
	if (a2n % n == 0) {
		mx = a2n / n;
	} else {
		mx = a2n / n + 1 ;
	}
	nx = a2n % n;
	if (nx == 0) {
		nx = n;
	}
	if (mx % 2 != 1) {
		if (n == 2) {
			if (nx == 2) {
				cout << mx << 1;
				return 0;
			} else {
				cout << mx << 2;
				return 0;
			}
		}
		if (nx % 2 == 1) {
			if (nx > n / 2 + 1)
				nx = nx - 2 * (nx - (n / 2 + 1));
			if (nx < n / 2 + 1)
				nx = nx + 2 * ((n / 2 + 1) - nx);
		} else {
			if (nx > n / 2 + 1)
				nx = 2 * (nx - (n / 2 + 1)) + 1;
			if (nx < n / 2)
				nx = 2 * ((n / 2) - nx) + 1;
		}
	} else {

	}

	cout << mx << ' ' << nx;

	return 0;
}