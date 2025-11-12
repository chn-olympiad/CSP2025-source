#include <bits/stdc++.h>
#define min3(a,b,c) min(a,min(b,c))
using namespace std;

const int N = 1e5+5;
int T, n;

struct A {
	int t1, t2, t3;
} a[N];

struct Dp {
	int f, cnt1, cnt2, cnt3;
} dp[N][4];

bool cmp(A a, A b) {
	int suma = a.t1 + a.t2 + a.t3;
	int sumb = b.t1 + b.t2 + b.t3;
	if (a.t1 == b.t1) {
		if (a.t2 == b.t2) {
			if (a.t3 == b.t3) {
				return suma < sumb;
			}
			return a.t3 < b.t3;
		}
		return a.t2 < b.t2;
	}
	return a.t1 < b.t1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		int l = n / 2; //先求限制
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].t1, &a[i].t2, &a[i].t3);
		}

		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].t2 != 0 || a[i].t3 != 0) {
				flag = 1;//有一个不是零则不符合这个测试点
			}
		}

		sort(a + 1, a + 1 + n, cmp);
		int ans = 0;

		if (flag != 1) {//全都是零
			for (int i = n; i >= n / 2 + 1 ; i--) {
				ans += a[i].t1;
			}
			printf("%d\n", ans);
			continue;
			printf("DEBUG\n");
		}

		for (int i = 1; i <= n; i++) { //第i个
			for (int j = 1; j <= 3; j++) { //第j
				dp[i][1].f = max(dp[i][1].f, min3(dp[i - 1][1].f, dp[i - 1][2].f, dp[i - 1][3].f));
				dp[i][2].f = max(dp[i][2].f, min3(dp[i - 1][1].f, dp[i - 1][2].f, dp[i - 1][3].f));
				dp[i][3].f = max(dp[i][3].f, min3(dp[i - 1][1].f, dp[i - 1][2].f, dp[i - 1][3].f));
				if (dp[i - 1][j].cnt1 + 1 <= l) { //可以选第1组
					if (dp[i][1].f < dp[i - 1][j].f + a[i].t1) { //
						dp[i][1].f = dp[i - 1][j].f + a[i].t1;
						dp[i][1].cnt1 = dp[i - 1][j].cnt1 + 1;
					}
				}
				if (dp[i - 1][j].cnt2 + 1 <= l) { //可以选第2组
					if (dp[i][2].f < dp[i - 1][j].f + a[i].t2) { //
						dp[i][2].f = dp[i - 1][j].f + a[i].t2;
						dp[i][2].cnt2 = dp[i - 1][j].cnt2 + 1;
						//printf("DEBUG %d\n", i);
					}
				}
				if (dp[i - 1][j].cnt3 + 1 <= l) { //可以选第3组
					if (dp[i][3].f < dp[i - 1][j].f + a[i].t3) { //
						dp[i][3].f = dp[i - 1][j].f + a[i].t3;
						dp[i][3].cnt3 = dp[i - 1][j].cnt3 + 1;
					}
				}
			}
		}
		ans = max(dp[n][1].f, max(dp[n][2].f, dp[n][3].f));
		printf("%d\n", ans);
	}
	return 0;
}