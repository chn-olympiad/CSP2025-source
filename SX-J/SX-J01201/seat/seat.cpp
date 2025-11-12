#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110], n, m, se, x, y;

bool cmp(ll xx, ll yy) {
	return xx > yy;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++)
		cin >> a[i];
	sort(a + 2, a + n *m + 1, cmp);
	for (ll i = 2; i <= n * m; i++) {
		if (a[1] > a[i]) {
			se = i - 1;
			break;
		}
	}
	if (se == 0)
		se = n * m;
	y = (se + n - 1) / n;
	if (y % 2 == 1) {
		x = se % n;
		if (x == 0)
			x = n;
	} else
		x = (n - se % n + 1);

	cout << y << " " << x;
	return 0;
}