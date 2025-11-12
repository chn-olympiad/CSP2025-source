#include <bits/stdc++.h>
int t, n, a[4][100001], f[100001], p[4], ans;

inline void solve(int x, int sum) {
	if (x > n) {
		//printf("try:");
		//for (int i = 1; i <= n; i++)
		//	printf("%d ", f[i]);
		//printf("\n    %d\n", sum);
		ans = std::max(sum, ans);
		return;
	}
	for (int i = 1; i < 4; i++) {
		f[x] = i;
		p[i]++;
		if (p[i] > n / 2) {
			p[i]--;
			continue;
		}
		solve(x + 1, sum + a[i][x]);
		p[i]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (scanf("%d", &t); t--;) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[1][i], &a[2][i], &a[3][i]);
		int a2 = 0, a3 = 0;
		for (int i = 1; i <= n; i++) {
			a2 += a[2][i];
			a3 += a[3][i];
		}
		if (a2 == a3 && a2 == 0) {
			std::sort(a[1] + 1, a[1] + n + 1);
			for (int i = n; i > n / 2; i--)
				ans += a[1][i];
			printf("%d\n", ans);
		} else {
			solve(1, 0);
			printf("%d\n", ans);
		}
	}
}
