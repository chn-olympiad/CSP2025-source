#include <bits/stdc++.h>
using namespace std;
int m, n, v, a[105], c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	v = a[1];
	sort(a + 1, a + (m *n) + 1);
	int ans;
	for (int i = 1; i <= (m * n); i++) {
		if (v == a[i]) {
			ans = i;
		}
	}
	ans = (m *n) - ans + 1;
	c = (ans - 1) / n + 1;
	if (c % 2 == 0) {
		r = n - (ans - (n*(c - 1))) + 1;
	} else {
		r = ans - (n*(c - 1));
	}
	cout << c << " " << r;
	return 0;
}
