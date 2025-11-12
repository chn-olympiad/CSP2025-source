#include <bits/stdc++.h>
using namespace std;
int n, m, d, t, at, bt, ct, a[100005][9], aa[100005], ab[100005], ac[100005], dp[300][300][300], ans;

bool cmp(int q, int w) {
	return aa[q] > aa[w];
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		d = 0;
		at = 0;
		bt = 0;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][1])
				at = 1;
			if (a[i][2])
				bt = 1;
			aa[i] = a[i][0];
			ab[i] = a[i][1];
		}
		if (n > 300) {
			if (!at && !bt) {
				sort(aa + 1, aa + 1 + n, cmp);
				for (int i = 1; i <= n / 2; i++) {
					ans += aa[i];
				}
			}
			cout << ans << endl;
			continue;
		}
		long long nt = n / 2;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= nt; j++) {
				for (int k = 0; k <= nt; k++) {
					int l = i - j - k;
					if (l < 0) {
						continue;
					}
					if (j + 1 <= nt) {
						int nj = j + 1, nk = k, nl = l;
						int nv = dp[i][j][k] + a[i + 1][0];
						if (nv > dp[i + 1][nj][nk]) {
							dp[i + 1][nj][nk] = nv;
						}
					}
					if (k + 1 <= nt) {
						int nj = j, nk = k + 1, nl = l;
						int nv = dp[i][j][k] + a[i + 1][1];
						if (nv > dp[i + 1][nj][nk]) {
							dp[i + 1][nj][nk] = nv;
						}
					}
					if (l + 1 <= nt) {
						int nj = j, nk = k, nl = l + 1;
						int nv = dp[i][j][k] + a[i + 1][2];
						if (nv > dp[i + 1][nj][nk]) {
							dp[i + 1][nj][nk] = nv;
						}
					}
				}
			}
		}
		for (int j = 0; j <= nt; j++) {
			for (int k = 0; k <= nt; k++) {
				int l = n - j - k;
				if (l >= 0 && l <= n / 2) {
					ans = max(ans, dp[n][j][k]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}