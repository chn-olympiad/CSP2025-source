#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, aa, l = 1;
	cin >> n >> m >> aa;
	a[1] = aa;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	while (a[l] != aa)
		l++;
	c = ceil(l * 1.0 / n);
	if (c % 2)
		r = l % n;
	else
		r = n - l % n + 1;
	if (r == 0)
		r = n;
	cout << c << ' ' << r;
	return 0;
}