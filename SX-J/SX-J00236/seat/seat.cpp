#include <bits/stdc++.h>
using namespace std;
int n, m;

struct node {
	int bh;
	int fs;
};
node a[1000], r;

bool cmp(node x, node y) {
	return x.fs > y.fs;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].fs;
		if (i == 1)
			r.fs = a[1].fs;
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		a[i].bh = i;
		if (a[i].fs == r.fs) {
			r.bh = a[i].bh;
			break;
		}
	}
	int x = r.bh;
	if (x % (2 * n) <= n && x % (2 * n) != 0) {
		cout << x / (2 * n) * 2 + 1 << " " << x % (2 * n);
	} else {

		cout << (x + n - 1) / n  << " " << n - (x - 1) % n;
	}
	return 0;
}
