#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], r, p, o, b, c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + m *n + 1);
	for (int i = 1; i <= m * n; i++) {
		if (r == a[i]) {
			p = n * m - i + 1;
			break;
		}
	}
	b = p / n;
	c = p % n;
	if (c == 0 and b % 2 == 0) {
		cout << b << " " << 1;
	} else if (c == 0 and b % 2 != 0) {
		cout << b << " " << n;
	} else if (b % 2 == 0) {
		cout << b + 1 << " " << c;
	} else if (b % 2 != 0) {
		cout << b + 1 << " " << n + 1 - c;
	}
	return 0;
}
