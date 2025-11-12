#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, w;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			w = a[i];
		}
	}
	sort(a + 1, a + n *m + 1);
	int me;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == w) {
			me = n * m - i + 1;
		}
	}
	int h, l;
	l = me / n + 1;
	if (me % n == 0) {
		l -= 1;
	}
	if (l % 2 == 1) {
		h = me % n;
		if (h == 0) {
			h = n;
		}
	} else {
		if (me % n == 0) {
			h = 1;
		} else {
			h = n - me % n + 1;
		}
	}
	cout << l << " " << h;
	return 0;
}
