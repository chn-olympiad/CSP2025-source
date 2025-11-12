#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N][N][N];
int a[3][N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n, ans = 0, cnt1 = 0, cnt2 = 0, cnt0 = 0;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if (a[0][i])
				cnt0++;
			if (a[1][i])
				cnt1++;
			if (a[2][i])
				cnt2++;
		}
		if (cnt1 == 0 && cnt2 == 0) {
			sort(a[0] + 1, a[0] + n + 1);
			for (int i = n; i > n / 2; i++) {
				ans += a[0][i];
			}
			continue;
		}
		if (cnt0 == 0 && cnt2 == 0) {
			sort(a[1] + 1, a[1] + n + 1);
			for (int i = n; i > n / 2; i++) {
				ans += a[1][i];
			}
			continue;
		}
		if (cnt0 == 0 && cnt1 == 0) {
			sort(a[2] + 1, a[2] + n + 1);
			for (int i = n; i > n / 2; i++) {
				ans += a[2][i];
			}
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int f = min(n / 2, i); f >= 0; f--) {
				for (int s = min(i - f, n / 2); s >= 0; s--) {
					int t = i - f - s;
					if (t > n / 2)
						continue;
					if (f != 0)
						dp[f][s][t] = max(dp[f][s][t], dp[f - 1][s][t] + a[0][i]);
					if (s != 0)
						dp[f][s][t] = max(dp[f][s][t], dp[f][s - 1][t] + a[1][i]);
					if (t != 0)
						dp[f][s][t] = max(dp[f][s][t], dp[f][s][t - 1] + a[2][i]);
				}

			}
		}

		for (int f = n / 2; f >= 0; f--) {
			for (int s = min(n - f, n / 2); s >= 0; s--) {
				int t = n - f - s;
				if (t > n / 2)
					continue;
				ans = max(ans, dp[f][s][t]);
			}
		}
		cout << ans << endl;
	}


	return 0;
}