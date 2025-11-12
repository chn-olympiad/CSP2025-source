#include <bits/stdc++.h>
const int N = 2e2+5;

struct Po {
	int a[5];
} p[N];
int f[N / 2][N / 2][N / 2];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(f, 0, sizeof f);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &p[i].a[1], &p[i].a[2], &p[i].a[3]);
		}
		int maxn = 0;
		memset(f, 0, sizeof f);
		for (int in = 1; in <= n; in++) {
			for (int i = n / 2; i >= 0; i--) {
				for (int j = n / 2; j >= 0; j--) {
					for (int k = n / 2; k >= 0; k--) {
						if (i + j + k > n)
							continue;
						if (i != 0)
							f[i][j][k] = std::max(f[i - 1][j][k] + p[in].a[1], f[i][j][k]);
						if (j != 0)
							f[i][j][k] = std::max(f[i][j - 1][k] + p[in].a[2], f[i][j][k]);
						if (k != 0)
							f[i][j][k] = std::max(f[i][j][k], f[i][j][k - 1] + p[in].a[3]);
						maxn = std::max(maxn, f[i][j][k]);
					}
				}
			}
		}
		printf("%d\n", maxn);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
