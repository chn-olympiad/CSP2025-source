#include <bits/stdc++.h>
using namespace std;
int a[101];

int cmp(int p, int b) {
	return p > b;
}

int main() {
	foropen("seat.in", "r", stdin);
	foropen("seat.out", "w", stdout);
	int n, m, l, c = 3, r = 2, i, s, f, p;
	cin >> n >> m;
	for (i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	p = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (i = 1; i <= n * m; i++) {
		if (p == a[i])
			l = i;
	}
	s = 1;
	f = n;
	for (i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			if (s <= l && f >= l) {
				r = l % n ;
				if (r == 0) {
					r = n;
				}
				c = i;

				break;
			}
		} else {
			if (s <= l && f >= l) {
				c = i;
				for (int k = s; k <= f; k++) {
					if (p == a[k]) {
						r = k - 1;
						break;
					}
				}
				break;
			}
		}
		s += n;
		f += n;
	}


	cout << c << ' ' << r;
	return 0;
}