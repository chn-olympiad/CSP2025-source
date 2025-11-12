// YN-S00215 T1 60PTS
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> vec(n + 1, vector<int>(4, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> vec[i][j];
		}
	}

	int lim = n >> 1;
	// cout << lim << endl;
	if (n <= 200) {
		vector<vector<vector<int>>> dp
		(n + 5, vector<vector<int>>(lim + 2,
		                            vector<int>(lim + 2, 0)));
		// increment club 1
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= lim; j++) {
				for (int k = 0; k <= lim; k++) {
					int l = i - j - k;
					if (l > lim) {
						continue;
					}
					// current: dp[i][j][k](l)
					// we want to evaluate with dp[i - 1] stuff
					// Currently the dp evaluates to zero
					// So we do not have anything
//					dp[i][j][k] =
//					    max(dp[i - 1][j - 1][k] + vec[i][1],
//					        max(dp[i - 1][j][k - 1] + vec[i][2],
//					            dp[i - 1][j][k] + vec[i][3]));
					if (j > 0) {
						dp[i][j][k] = max(dp[i][j][k],
						                  dp[i - 1][j - 1][k] + vec[i][1]);
					}
					if (k > 0) {
						dp[i][j][k] = max(dp[i][j][k],
						                  dp[i - 1][j][k - 1] + vec[i][2]);
					}
					if (l > 0) {
						dp[i][j][k] = max(dp[i][j][k],
						                  dp[i - 1][j][k] + vec[i][3]);
					}
					// cout << "dp: " <<
					//      i << " " << j << " " << k << " " << dp[i][j][k] << endl;
				}
			}
		}

		int maxElm = 0;
		for (int j = 1; j <= lim; j++) {
			for (int k = 1; k <= lim; k++) {
				int l = n - j - k;
				if (l > lim) {
					continue;
				}

				maxElm = max(maxElm, dp[n][j][k]);
			}
		}
		cout << maxElm << endl;
	} else {
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			a.push_back(vec[i][1]);
		}
		sort(a.rbegin(), a.rend());
		int sum = 0;
		for (int i = 0; i < lim; i++) {
			sum += a[i];
		}
		cout << sum << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++) {
		solve();
	}
	return 0;
}