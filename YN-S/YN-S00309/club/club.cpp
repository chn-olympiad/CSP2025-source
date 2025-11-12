#include <bits/stdc++.h>
#define maxn 100500
#define ll long long
using namespace std;
ll t, n, a[maxn][5], dp[maxn][5][3], s[maxn][5][3][3], s1[5];
int ans;

void dfs(int k, int m, int as) {
	if (k == n + 1) {
		ans = max(ans, as);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (s1[i] < n / 2) {
			s1[i]++;
			dfs(k + 1, i, as + a[k][m]);
			s1[i]--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		ans = 0;
		memset(s1, 0, sizeof(s1));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (n > 100000) {
			if (a[1][2] == 0 && a[1][3] == 0 && a[2][2] == 0 && a[2][3] == 0) {
				int r[maxn];
				for (int i = 1; i <= n; i++) {
					r[i] = a[i][1];
				}
				sort(r + 1, r + 1 + n);
				int as = 0;
				for (int i = n; i > n / 2; i++) {
					as += r[i];
				}
				cout << as << "\n";
				continue;
			}
		}
		if (n > 100) {
			for (int i = 1; i <= n; i++) {
				for (int m = 1; m <= 3; m++) {
					for (int l = 1; l <= 3; l++) {
						if (dp[i - 1][l][0] < dp[i - 1][l][1]) {
							dp[i][m][0] = dp[i - 1][l][1];
							for (int o = 1; o <= 3; o++)
								s[i][m][0][o] = s[i - 1][l][1][o];
						} else {
							dp[i][m][0] = dp[i - 1][l][0];
							for (int o = 1; o <= 3; o++)
								s[i][m][0][o] = s[i - 1][l][0][o];
						}
						if (s[i - 1][l][0][m] < n / 2) {
							if (dp[i][m][1] < dp[i - 1][l][0] + a[i][m]) {
								dp[i][m][1] = dp[i - 1][l][0] + a[i][m];
								for (int o = 1; o <= 3; o++)
									s[i][m][1][o] = s[i - 1][l][0][o];
								s[i][m][1][m] = s[i - 1][l][0][m] + 1;
							}
						}
						if (s[i - 1][l][1][m] < n / 2) {
							if (dp[i][m][1] < dp[i - 1][l][1] + a[i][m]) {
								dp[i][m][1] = dp[i - 1][l][1] + a[i][m];
								for (int o = 1; o <= 3; o++)
									s[i][m][1][o] = s[i - 1][l][1][o];
								s[i][m][1][m] = s[i - 1][l][1][m] + 1;
							}
						}
					}
				}
			}
			ll as = 0;
			for (int i = 1; i <= 3; i++) {
				as = max(as, max(dp[n][i][1], dp[n][i][0]));
			}
			cout << as << "\n";
			continue;
		}
		dfs(0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}

