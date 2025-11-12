#include <bits/stdc++.h>
using namespace std;

int n, m, p, e, h, l;

struct node {
	int g;
	int p;
};

node a[105];

bool cmp(node x, node y) {
	if (x.g > y.g)
		return true;
	else
		return false;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].g;
		p++;
		a[i].p = p;
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].p == 1)
			e = i;
	}
	if (e % n == 0) {
		if ((e / n) % 2 == 0) {
			h = 1;
			l = e / n;
		} else {
			h = n;
			l = e / n;
		}
	} else {
		if ((e / n) % 2 != 0) {
			h = n - (e % n) + 1;
			l = e / n + 1;
		} else {
			h = e % n;
			l = e / n + 1;
		}
	}
	cout << l << ' ' << h;
	return 0;
}
