#include <bits/stdc++.h>
using namespace std;
long long n, m, k;

struct st {
	long long s;
	bool f;
} a[1005];

bool cmp(st x, st y) {
	return x.s > y.s;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].s;
		if (i == 1)
			a[i].f = 1;
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m ; i++) {
		if (a[i].f == 1) {
			k = i;
			break;
		}
	}
	if (n == 1) {
		cout << k << " " << 1;
		return 0;
	} else if (m == 1) {
		cout << 1 << " " << k;
		return 0;
	} else {
		if (k <= n) {
			cout << 1 << " " << k;
			return 0;
		} else {
			long long p = ceil(1.0 * k / n);
			cout << p << " ";
			if (p % 2 == 0) {
				if (k % n != 0)
					cout << n - k % n + 1 ;
				else
					cout << 1;
			} else {
				if (k % n != 0)
					cout << k % n ;
				else
					cout << n;
			}
		}
	}
	return 0;
}
