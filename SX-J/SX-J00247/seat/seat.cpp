#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, ans, k, step, q, sp;
int a[10086], b[10086][10086];

int cmp(int d, int c) {
	return d > c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];

	}
	ans = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m ; i++) {
		q++;
		for (int l = 1; l <= n; l++) {
			sp++;
			b[l][q] = a[sp];
		}
		q++;
		for (int l = n; l >= 1; l--) {
			sp++;
			b[l][q] = a[sp];

		}
	}
	for (int i = 1; i <= n * m ; i++) {
		k++;
		for (int l = 1; l <= n; l++) {
			step++;
			if (b[l][k] == ans) {
				cout << k << " " << l;
				return 0;
			}
		}
		k++;
		for (int l = n; l >= 1; l--) {
			step++;
			if (b[l][k] == ans) {
				cout << k << " " << l;
				return 0;
			}
		}
	}

	return 0;
}
