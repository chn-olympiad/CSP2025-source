#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, l;
	cin >> n >> m;
	int r;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			l = i;
			break;
		}
	}
	l = n * m - l + 1;
	if (l % m == 0) {
		l /= m;
		if (l % 2 == 0)
			cout << l << " 1";
		else
			cout << l << " " << n;
	} else {
		int x = l % m;
		l /= m;
		if (l % 2 == 0)
			cout << l + 1 << " " << x;
		else
			cout << l + 1 << " " << n - x + 1;
	}
	return 0;
}
