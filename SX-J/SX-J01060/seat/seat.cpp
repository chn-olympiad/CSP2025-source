#include <bits/stdc++.h>
using namespace std;
long long a, n, m, o = 1, r = 1;

struct vc {
	int x, ui;
} v[10010];

int cmp(vc c, vc b) {
	return c.x > b.x;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> v[i].x;
		v[i].ui = i;
	}
	sort(v + 1, v + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (v[i].ui == 1) {
			cout << o << " " << r;
		}
		if (o % 2 != 0) {
			if (r != n) {
				r++;
			} else {
				o++;
			}
		} else {
			if (r != 1) {
				r--;
			} else {
				o++;
			}
		}
	}
	return 0;
}
