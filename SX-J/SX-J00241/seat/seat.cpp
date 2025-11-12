#include <bits/stdc++.h>
using namespace std;
int n, m, sb, a[104];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	sb = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int x = 1; x <= n * m; x++) {
		if (a[x] == sb) {
			if (x % n == 0) {
				printf("%d ", x / n);
				if (x / n % 2 == 0)
					printf("1");
				else
					printf("%d", n);
			} else {
				printf("%d ", x / n + 1);
				if ((x / n + 1) % 2 == 0)
					printf("%d", n - x % n + 1);
				else
					printf("%d", x % n);
			}
			return 0;
		}
	}
	return 0;
}