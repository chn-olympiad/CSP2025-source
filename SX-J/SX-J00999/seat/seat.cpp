#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000], x, y, b, t;

bool cmp(long long a1, long long b1) {
	return a1 > b1;
}

signed main(void) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	b = a[1];
	for (long long i = 2; i <= n * m; ++i)
		cin >> a[i];
	sort(a + 1, a + n *m + 1, cmp);
	for (long long i = 1; i <= n * m; ++i) {
		if (a[i] == b)
			t = i;
	}
	if (t % n == 0) {
		if ((t / n) % 2 == 0)
			x = 1, y = t / n;
		else
			x = n, y = t / n;
	} else {
		if ((t / n) % 2 == 0)
			x = t % n, y = t / n + 1;
		else
			x = n - t % n + 1, y = t / n + 1;
	}
	cout << y << " " << x;
	return 0;
}
