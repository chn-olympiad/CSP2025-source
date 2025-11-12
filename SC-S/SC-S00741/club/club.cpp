#include <bits/stdc++.h>

bool f1 = true, f2 = true;

long long task = 0;
long long c[100005];
long long dp[2][205][205][205], a[5][100005];
long long n = 0, ans = 0; 
void solve1() {
	memset(c, 0, sizeof c);
	memset(a, 0, sizeof a);
	memset(dp, 0, sizeof dp);
	scanf("%lld", &n); ans = 0;
	for(long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= 3; j++) {
			scanf("%lld", &a[j][i]);
		}
	}
	long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(long long i = 1; i <= n; i++) {
		long long res = std::max(a[1][i], std::max(a[2][i], a[3][i]));
		if (a[1][i] == res) cnt1++;
		else if (a[2][i] == res) cnt2++;
		else cnt3++;
		ans += res;
	}
	if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
		printf("%lld\n", ans); return;
	} 
	for (long long i = 1; i <= n; i++) {
		if (!(a[3][i] == 0 && a[2][i] == 0)) f1 = false;
		if (a[3][i] != 0) f2 = false;
	}
	long long res = 0;
	if (f1) {
		std::sort(a[1] + 1, a[1] + 1 + n, std::greater < long long > ());
		for (long long i = 1; i <= n / 2; i++) {
			res += a[1][i];
		}
		printf("%lld\n", res);
		return;
	} else if (f2) {
		if (cnt1 > n / 2) {
			for (long long i = 1; i <= n; i++) {
				c[i] = a[1][i] - a[2][i];
			}
			std::sort(c + 1, c + 1 + n);
			for (long long i = 1; i <= cnt1 - n / 2; i++) {
				res -= c[i];
			}
		} else {
			for (long long i = 1; i <= n; i++) {
				c[i] = a[2][i] - a[1][i];
			}
			std::sort(c + 1, c + 1 + n);
			for (long long i = 1; i <= cnt2 - n / 2; i++) {
				res -= c[i];
			}
		}
		printf("%lld\n", res);
		return;
	} else if (n <= 200) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 0; j <= i; j++) {
				for (long long k = 0; k + j <= i; k++) {
					dp[1][j][k][i - j - k] = 0;
					if (j > 0)
						dp[1][j][k][i - j - k] = std::max(dp[0][j - 1][k][i - j - k] + a[1][i], dp[1][j][k][i - j - k]);
					if (k > 0)
						dp[1][j][k][i - j - k] = std::max(dp[0][j][k - 1][i - j - k] + a[2][i], dp[1][j][k][i - j - k]);
					if (i - j - k > 0)
						dp[1][j][k][i - j - k] = std::max(dp[0][j][k][i - j - k - 1] + a[3][i], dp[1][j][k][i - j - k]);
				}
			}
			for (long long j = 0; j <= i; j++) {
				for (long long k = 0; k + j <= i; k++) {
					dp[0][j][k][i - j - k] = dp[1][j][k][i - j - k];
				}
			}
		}
		for (long long j = 0; j <= n; j++) {
			for (long long k = 0; k + j <= n; k++) {
				ans = std::max(ans, dp[1][j][k][n - j - k]);
			}
		}
		printf("%lld\n", ans);
	}
}
int main() {
	freopen("club.in", "r", stdin);	
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &task);
	
	while (task--) {
		solve1();
	}	
	return 0;
} 