#include <bits/stdc++.h>
using namespace std;

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int xr = a[1], w;
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == xr) {
			w = i;
			break;
		}
	}
	if (w % n > 0) {
		if ((w / n + 1) % 2 == 1)
			cout << w / n + 1 << " " << w % n;
		else
			cout << w / n + 1 << " " << n - w % n + 1;
	} else {
		if ((w / n) % 2 == 1)
			cout << w / n << " " << n;
		else
			cout << w / n << " " << 1;
	}
	return 0;
}
