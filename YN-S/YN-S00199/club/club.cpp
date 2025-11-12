#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int T, n;
int a[N][4], b[N];
int ans = 0, cnt[4];
int f[205][105][105][105];

void dfs(int cur, int tot) {
	if (cur > n) {
		ans = max(ans, tot);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] + 1 > n / 2)
			continue;
		int tmp = tot + a[cur][i];
		cnt[i]++;
		dfs(cur + 1, tmp);
		cnt[i]--;
	}
	return;
}

bool cmp(int x, int y) {
	return x > y;
}

void work() {

	scanf("%d", &n);
	bool fl = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		if (a[i][2] != 0 || a[i][3] != 0)
			fl = false;
	}
	if (n <= 10) {
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	} else if (fl == true) {
		for (int i = 1; i <= n; i++) {
			b[i] = a[i][1];
		}
		sort(b + 1, b + 1 + n, cmp);
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			ans += b[i];
		}
		printf("%d\n", ans);
	} else {
		memset(f, 0, sizeof f);
		for (int j = 1; j <= n / 2; j++) {
			for (int k = 1; k <= n / 2; k++) {
				for (int l = 1; l <= n / 2; l++) {
					for (int i = 1; i <= n; i++) {
						if (i > j + k + l)
							break;
						f[i][j][k][l] = max(f[i][j][k][l], max(max(f[i - 1][j - 1][k][l] + a[i][1], f[i - 1][j][k - 1][l] + a[i][2]),
						                                       f[i - 1][j][k][l - 1] + a[i][3]));
					}
				}
			}
		}
		printf("%d\n", f[n][n / 2][n / 2][n / 2]);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}