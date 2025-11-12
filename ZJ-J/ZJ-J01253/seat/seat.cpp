#include <cstdio>
int a[11][11];
int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	int n, m, rnk = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			scanf("%d", &a[i][j]);
			if (a[i][j] > a[1][1]) {
				rnk ++ ;
			}
		}
	}
	if (!rnk) {
		printf("1 1");
	} else {
		bool f = 0;
		int i = 1, j = 1;
		while (1) {
			for (int b = 1; b <= n - 1; b ++ ) {
				if (f) {
					i -- ;
				} else {
					i ++ ;
				}
				rnk -- ;
				if (!rnk) {
					printf("%d %d", j, i);
					return 0;
				}
			}
			j ++ , rnk -- , f = !f;
			if (!rnk) {
				printf("%d %d", j, i);
				return 0;
			}
		}
	}
}
