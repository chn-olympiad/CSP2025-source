#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], k = 1, d;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	d = a[1];
	sort(a + 1, a + 1 + n *m, greater<int>());
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				if (a[k] == d) {
					printf("%d %d", i, j);
					return 0;
				}
				k++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				if (a[k] == d) {
					printf("%d %d\n", i, j);
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
