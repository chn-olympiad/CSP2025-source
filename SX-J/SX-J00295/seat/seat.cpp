#include <bits/stdc++.h>
using namespace std;
const int maxN = 105, maxM = 15;
int n, m, c, r, a[maxN], b[maxM][maxM];
int k, cnt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	k = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				b[i][j] = a[++cnt];
			}
		} else {
			for (int j = 1; j <= n; j++) {
				b[i][j] = a[++cnt];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == k) {
				c = i;
				r = j;
			}
		}
	}
	printf("%d %d", c, r);
	return 0;
}
