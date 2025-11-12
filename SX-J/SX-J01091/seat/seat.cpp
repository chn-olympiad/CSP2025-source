#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", 'w', stdout);
	int n, m, r, rk;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", a + i);
	r = a[1];
	sort(a + 1, a + n *m + 1, greater<int> ());
	for (int i = 1; i <= n * m; i++)
		if (a[i] == r) {
			rk = i;
			break;
		}
	int x = rk % n, y = rk / n;
	if (y % 2 == 0) {
		if (x == 0)
			printf("%d 1", y);
		else
			printf("%d %d", y + 1, x);
	} else {
		if (x == 0)
			printf("%d %d", y, n);
		else
			printf("%d %d", y + 1, n - x + 1);
	}
	return 0;
}