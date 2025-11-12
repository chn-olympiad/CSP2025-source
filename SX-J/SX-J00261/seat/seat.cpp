#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &a[1]);
	int l = a[1], c = 1;
	for (int i = 2; i <= n * m; i++) {
		scanf("%d", &a[i]);
		if (a[i] > l)
			c++;
	}
	int x = c / n, y;
	if (c % n != 0) {
		x++;
		if (x % 2 != 0)
			y = c % n;
		else
			y = n - (c % n) + 1;
	} else {
		if (x % 2 != 0)
			y = n;
		else
			y = 1;
	}
	printf("%d %d\n", x, y);
	return 0;
}
