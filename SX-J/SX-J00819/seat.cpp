#include <bits/stdc++.h>
using namespace std;

int n, m, my, a[1000091], x, y;

bool I(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	my = a[1];
	sort(a + 1, a + 1 + n *m, I);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == my) {
			my = i;
			break;
		}
	}
	x = my / n;
	if (my % n > 0) {
		x += 1;
	}
	y = my % m;
	if (y == 0) {
		y += n;
	}
	if (x % 2 == 0) {
		y = n - y + 1;
	}
	printf("%d %d", x, y);
	return 0;
}