#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[105];

bool cmp(int l, int r) {
	return l > r;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, s;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1, cmp);

	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			s = i;
			break;
		}
	}
	int y;
	x = s / n;
	y = s % n;
	if (y == 0) {
		if (x % 2 == 1) {
			cout << x << ' ' << n;
		} else {
			cout << x << ' ' << 1;
		}
	} else {
		x++;
		if (x % 2 == 1) {
			cout << x << ' ' << y;
		} else {
			cout << x << ' ' << n - y + 1;
		}
	}
	return 0;
}
