#include <cstdio>
#include <algorithm>
#include <cstring>
int a[100001][4], b[4], c[100001][4], d[100001];
int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t -- ) {
		memset(a, 0, sizeof a), memset(b, 0, sizeof b), memset(c, 0, sizeof c), memset(d, 0, sizeof d);
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) {
			int mx = -1, mxid = -1;
			for (int j = 1; j <= 3; j ++ ) {
				scanf("%d", &a[i][j]);
				if (mx < a[i][j]) {
					mx = a[i][j], mxid = j;
				}
			}
			b[mxid] ++ , ans += mx;
			for (int j = 1; j <= 3; j ++ ) {
				c[i][j] = a[i][j] - mx;
			}
		}
		for (int i = 1; i <= 3; i ++ ) {
			if (b[i] > n / 2) {
				for (int j = 1; j <= 100001; j ++ ) {
					d[j] = -1;
				}
				for (int j = 1; j <= n; j ++ ) {
					for (int k = 1; k <= 3; k ++ ) {
						if (!c[j][k]) {
							continue;
						}
						d[j] = std::max(d[j], c[j][k]);
					}
				}
				std::sort(d + 1, d + n + 1), std::reverse(d + 1, d + n + 1);
				for (int j = 1; j <= b[i] - n / 2; j ++ ) {
					ans += d[j];
				}
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}
