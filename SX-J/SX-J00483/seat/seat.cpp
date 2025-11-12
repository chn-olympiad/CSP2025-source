#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], r, pm, zx, zy;

bool pj(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++) {
		scanf("%d", &a[i]);
		if (i == 1) {
			r = a[i];
		}
	}
	sort(a + 1, a + 1 + n *m, pj);
	for (int i = 1; i <= n * m; i ++) {
		if (r == a[i]) {
			pm = i;
			break;
		}
	}
	if (pm % n == 0) {
		zx = pm / n;
	} else {
		zx = pm / n + 1;
	}
	if (zx % 2 == 0) {
		zy = 1 + zx * n - pm;
	} else {
		zy = n - zx * n + pm;
	}
	printf("%d %d", zx, zy);
	return 0;
}
