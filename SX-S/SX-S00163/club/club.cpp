#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001][4], club[100001], mx, ans, club1, club2, club3, cur, dp[100001], mxcur;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		club1 = 0;
		club2 = 0;
		club3 = 0;
		ans = 0;
		mx = 0;
		mxcur = 0;
		for (int j = 1; j <= n; j++) {
			dp[j] = 0;
			club[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			scanf("%d%d%d", &a[j][1], &a[j][2], &a[j][3]);
			mx = max(a[j][1], a[j][2]);
			mx = max(a[j][3], mx);
			if (mx == a[j][1]) {
				club[j] = 1;
				club1++;
			} else if (mx == a[j][2]) {
				club[j] = 2;
				club2++;
			} else {
				club[j] = 3;
				club3++;
			}
			ans += mx;
		}
		mx = max(club1, club2);
		mx = max(club3, mx);
		mxcur = mx;
		if (mx <= n / 2) {

		} else {
			if (mx == club1)
				cur = 1;
			else if (mx == club2)
				cur = 2;
			else
				cur = 3;
			for (int j = 1; j <= n; j++) {
				if (club[j] == cur) {
					mx = 0;
					for (int k = 1; k <= 3; k++) {
						if (k != cur)
							mx = max(mx, a[j][k]);
					}
					dp[j] = a[j][cur] - mx;
				} else
					dp[j] = INT_MAX;
			}
			sort(dp + 1, dp + n + 1);
			mx = mxcur;
			for (int j = 1; j <= mx - n / 2; j++) {
				ans -= dp[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
