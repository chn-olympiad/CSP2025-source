#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;

struct node {
	long long a1, a2, a3;
} a[300000];
long long ans;
long long cnt[10];
long long b[300000];
long long dp[40][40][40][40];
long long f[300][300][300];

bool cmp1(const node &x, const node &y) {
	if (x.a1 != y.a1)
		return x.a1 > y.a1;
	else
		return x.a2 > y.a2;
}

bool cmp2(const node &x, const node &y) {
	if (x.a2 != y.a2)
		return x.a2 > y.a2;
	else
		return x.a1 > y.a1;
}

void solve(long long id) {
	if (2 * cnt[1] > n || 2 * cnt[2] > n || 2 * cnt[3] > n)
		return;
	if (id > n) {
		long long sum = 0;
		for (long long i = 1; i <= n; i++) {
			if (b[i] == 1) {
				sum += a[i].a1;
			} else if (b[i] == 2) {
				sum += a[i].a2;
			} else if (b[i] == 3) {
				sum += a[i].a3;
			}
		}
		ans = max(ans, sum);
		return;
	}
	cnt[1]++;
	b[id] = 1;
	solve(id + 1);
	cnt[1]--;
	cnt[2]++;
	b[id] = 2;
	solve(id + 1);
	cnt[2]--;
	cnt[3]++;
	b[id] = 3;
	solve(id + 1);
	cnt[3]--;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%lld", &n);
		for (long long i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i].a1, &a[i].a2, &a[i].a3);
		}
		bool p = 0;
		for (long long i = 1; i <= n; i++) {
			if (a[i].a2 || a[i].a3) {
				p = 1;
				break;
			}
		}
		if (!p) {
			sort(a + 1, a + n + 1, cmp1);
			long long ans1 = 0;
			for (long long i = 1; i <= n / 2; i++) {
				ans1 += a[i].a1;
			}
			printf("%lld\n", ans1);
			continue;
		}
		if (n <= 10) {
			ans = 0;
			solve(1);
			printf("%lld\n", ans);
		} else if (n <= 30) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						for (int l = 0; l <= n; l++) {
							dp[i][j][k][l] = -(1LL << 60);
						}
					}
				}
			}
			dp[0][0][0][0] = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						for (int l = 0; l <= n; l++) {
							if (2 * (j + 1) <= n && j + 1 + k + l <= n) {
								dp[i + 1][j + 1][k][l] = max(dp[i + 1][j + 1][k][l], dp[i][j][k][l] + a[i + 1].a1);
							}
							if (2 * (k + 1) <= n && j + k + 1 + l <= n) {
								dp[i + 1][j][k + 1][l] = max(dp[i + 1][j][k + 1][l], dp[i][j][k][l] + a[i + 1].a2);
							}
							if (2 * (l + 1) <= n && j + k + l + 1 <= n) {
								dp[i + 1][j][k][l + 1] = max(dp[i + 1][j][k][l + 1], dp[i][j][k][l] + a[i + 1].a3);
							}
						}
					}
				}
			}
			long long ans1 = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						if (2 * i <= n && 2 * j <= n && 2 * k <= n && i + j + k == n) {
							ans1 = max(ans1, dp[n][i][j][k]);
						}
					}
				}
			}
			printf("%lld\n", ans1);
		} else if (n <= 200) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						f[i][j][k] = -(1LL << 60);
					}
				}
			}
			f[0][0][0] = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						if (2 * (j + 1) <= n && j + 1 + k <= n) {
							f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1].a1);
						}
						if (2 * (k + 1) <= n && j + k + 1 <= n) {
							f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k] + a[i + 1].a2);
						}
					}
				}
			}
			long long ans1 = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					if (2 * i <= n && 2 * j <= n  && i + j == n) {
						ans1 = max(ans1, f[n][i][j]);
					}
				}
			}
			printf("%lld\n", ans1);
		} else if (n <= 100000 && a[1].a3 == 0) {
			sort(a + 1, a + n + 1, cmp1);
			long long ans1 = 0;
			for (int i = 1; i * 2 <= n; i++) {
				ans1 += a[i].a1;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				ans1 += a[i].a2;
			}
			sort(a + 1, a + n + 1, cmp2);
			long long ans2 = 0;
			for (int i = 1; i * 2 <= n; i++) {
				ans2 += a[i].a2;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				ans2 += a[i].a1;
			}
			printf("%lld\n", max(ans1, ans2));
		} else {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						for (int l = 0; l <= n; l++) {
							dp[i][j][k][l] = -(1LL << 60);
						}
					}
				}
			}
			dp[0][0][0][0] = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						for (int l = 0; l <= n; l++) {
							if (2 * (j + 1) <= n && j + 1 + k + l <= n) {
								dp[i + 1][j + 1][k][l] = max(dp[i + 1][j + 1][k][l], dp[i][j][k][l] + a[i + 1].a1);
							}
							if (2 * (k + 1) <= n && j + k + 1 + l <= n) {
								dp[i + 1][j][k + 1][l] = max(dp[i + 1][j][k + 1][l], dp[i][j][k][l] + a[i + 1].a2);
							}
							if (2 * (l + 1) <= n && j + k + l + 1 <= n) {
								dp[i + 1][j][k][l + 1] = max(dp[i + 1][j][k][l + 1], dp[i][j][k][l] + a[i + 1].a3);
							}
						}
					}
				}
			}
			long long ans1 = 0;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					for (int k = 0; k <= n; k++) {
						if (2 * i <= n && 2 * j <= n && 2 * k <= n && i + j + k == n) {
							ans1 = max(ans1, dp[n][i][j][k]);
						}
					}
				}
			}
			printf("%lld\n", ans1);
		}
	}
	return 0;
}