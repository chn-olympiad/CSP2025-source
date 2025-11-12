#include <bits/stdc++.h>
using namespace std;

bool cmp (int x, int y) {
	if (x > y) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n = 0, m = 0, v[10009], c = 0, r = 0, o = 0, op = 0, g = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> v[i];
	}
	o = v[1];
	sort (v + 1, v + n *m + 1, cmp);
	while (1) {
		if (v[g] == o) {
			op = g;
			break;
		} else {
			g++;
		}
	}
	if (op % n == 0) {
		c = op / n;
		if (c % 2 == 1) {
			r = n;
		} else {
			r = 1;
		}
	} else {
		c = op / n + 1;
		if (c % 2 == 1) {
			r = op % n;
		} else {
			r = n - (op % n) + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}
