#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);//I love CCF
	int n, m, a[105] = {}, t = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[n * m + 1 - i] == t) {
			t = n * m + 1 - (n *m + 1 - i);
			break;
		}
	}
	int c, r;
	c = t / 3 + 1;
	cout << c;
	if (c % 2 == 1) {
		if (t == n) {
			r = t;
		} else {
			r = t - (t / n) * 3;
		}
	} else {
		r = n - ((t + 2) % m) + 1;
	}
	cout << " " << r;
	return 0;
}
