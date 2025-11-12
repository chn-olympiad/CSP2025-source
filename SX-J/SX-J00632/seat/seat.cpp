#include <bits/stdc++.h>
using namespace std;
int a[101], n, m, x, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	y = n * m;
	for (int i = 1; i <= y; i++)
		scanf("%d", &a[i]);
	x = a[1];
	sort(a + 1, a + y + 1);
	for (int i = y; i; i--)
		if (a[i] == x) {
			int j = y - i + 1;
			int c = j / n;
			if (j % n)
				c++;
			int r = j % n;
			if (!r)
				r = n;
			if (c % 2 == 0)
				r = n - r + 1;
			printf("%d %d\n", c, r);
		}
}