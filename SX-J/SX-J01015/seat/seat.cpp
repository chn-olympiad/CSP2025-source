#include <bits/stdc++.h>
using namespace std;
int m, n;

struct NODE {
	int a, code;
} n1[110];

bool cmp(NODE x, NODE y) {
	return x.a > y.a;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m * n; i++) {
		scanf("%d", &n1[i].a);
		n1[i].code = i;
	}
	sort(n1 + 1, n1 + 1 + m *n, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (n1[i].code == 1) {
			if (((i + n - 1) / n) % 2 == 1) {
				if (i % n == 0) {
					printf("%d %d\n", (i + n - 1) / n, n);
					break;
				}
				printf("%d %d\n", (i + n - 1) / n, i % n);
				break;
			} else {
				printf("%d %d\n", (i + n - 1) / n, n - (i % n) + 1);
				break;
			}

		}
	}
	return 0;
}