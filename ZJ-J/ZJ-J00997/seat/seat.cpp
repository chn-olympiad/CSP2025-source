#include <bits/stdc++.h>
using namespace std;
int main(void) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[200], x, p, c, r;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + n * m + 1);
	p = n * m - (lower_bound(a + 1, a + n * m + 1, x) - a) + 1;
	c = p % n ? p / n + 1 : p / n;
	r = c % 2 ? (p % n ? p % n : n) : n + 1 - (p % n ? p % n : n);
	cout << c << ' ' << r << endl;
	return 0;
}
