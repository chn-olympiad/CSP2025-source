#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;
typedef pair<int, int> PII;

LL n, a[N][4];

namespace subtask_1_to_4 {
	LL res = 0;
	
	void dfs(int u, LL c1, LL c2, LL c3, LL ans) {
		if (u == n + 1) {
			res = max(res, ans);
			return;
		}
		
		if (c1 + 1 <= n / 2) {
			dfs(u + 1, c1 + 1, c2, c3, ans + a[u][1]);
		}
		if (c2 + 1 <= n / 2) {
			dfs(u + 1, c1, c2 + 1, c3, ans + a[u][2]);
		}
		if (c3 + 1 <= n / 2) {
			dfs(u + 1, c1, c2, c3 + 1, ans + a[u][3]);
		} 
	}
	
	void solve() {
		res = 0;
		dfs(1, 0, 0, 0, 0);
		cout << res << "\n";
	}
};

namespace subtask_5_to_11 {
	const int M = 210;
	const LL INFLL = 1e15;
	LL dp[M][M / 2][M / 2];
	
	void solve() {
		int half = n / 2;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= half; j++) {
				for (int k = 0; k <= half; k++) {
					dp[i][j][k] = -INFLL;
				}
			}
		}
		
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i && j <= half; j++) {
				for (int k = 0; k <= i && k <= half; k++) {
					if (j + k > i) {
						break;
					}
					
					if (i - j - k > half) {
						continue;
					}
					
					if (j > 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
					}
					if (k > 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
					}
					if (i - j - k > 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
					}
				}
			}
		}
		
		LL res = 0;
		for (int j = 0; j <= half; j++) {
			for (int k = 0; k <= half; k++) {
				res = max(res, dp[n][j][k]);
			}
		}
		cout << res << "\n";
	}	
};

namespace subtask_12_to_14 {
	
	void solve() {
		vector<PII> b;
		for (int i = 1; i <= n; i++) {
			b.push_back({a[i][2] - a[i][1], i});
		}
		sort(b.begin(), b.end());
		LL res = 0;
		for (int i = 0; i < n / 2; i++) {
			res += a[b[i].second][1];
		}
		for (int i = n / 2; i < n; i++) {
			res += a[b[i].second][2];
		}
		cout << res << "\n";
	}	
};

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	if (n <= 200) {
		subtask_5_to_11::solve(); 
	} else {
		subtask_12_to_14::solve();
	}
}

int main() {
	#ifndef ZCX
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
}
