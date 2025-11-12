#include <bits/stdc++.h>
using namespace std;
long long n, m, a[20][20], c, r, b[400], d, t, e[20][20];

long long cmp(long long x, long long y) {
	return x > y;
};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	d = b[1];
	if (n == 1 && m == 1) {
		cout << b[1];
		return 0;
	}

	sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (d == b[i]) {
			t = i;
		}
	}
	if (n == 1) {
		for (int i = 1; i <= m; i++) {
			if (b[t] == b[i]) {
				cout << "1" << " " << i;
				return 0;
			}
		}
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (b[t] == b[i]) {
				cout << i << " " << "1";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[t] == b[i]) {
				c = i;
				r = j;
			}
		}
	}
	//cout << r << " " << c;
	return 0;
}
