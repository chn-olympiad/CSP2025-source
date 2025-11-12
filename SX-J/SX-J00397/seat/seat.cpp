#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1);
	int t = lower_bound(a + 1, a + n *m + 1, s) - a;
	t = n * m + 1 - t;
	int x = (t - 1) / n + 1, y;
	if (x % 2 == 0) {
		y = n + 1 - ((t - 1) % n + 1);
	} else {
		y = (t - 1) % n + 1;
	}
	cout << x << " " << y;
	return 0;
}