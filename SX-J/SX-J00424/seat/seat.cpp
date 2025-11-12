#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105], t, cnt, c, r, q;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m >> t;
	a[1] = t;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		for (int j = 1; j <= i - 1; j++) {
			if (a[i] > a[j]) {
				q = a[i];
				a[i] = a[j];
				a[j] = q;
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		b[i] = a[i];
	}

	for (int i = 1; i <= n * m; i++) {
		if (t == b[i])
			cnt = i;
	}
	c = cnt / n;
	r = cnt % n;
	if (r == 0) {
		if (c % 2 == 1)
			cout << c << " " << n;
		else
			cout << c << " " << 1;
	} else if (c % 2 == 0) {
		cout << c + 1 << " " << r;
	} else {
		cout << c + 1 << " " << n + 1 - r;
	}
	return 0;
}
