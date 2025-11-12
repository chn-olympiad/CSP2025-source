#include <bits/stdc++.h>
using namespace std;
const  int N = 1e3 + 10;

int w[N], v[N];
int dp[N][N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 3 * n; i++) {
			cin >> v[i] ;
			w[i] = 1;
		}
		for (int i = 1; i <= 3 * n; i++) {
			for (int j = 1; j <= n / 2; j++) {
				if (i % 3 == 0) {
					dp[3][j] = max(dp[3][j - 1], dp[3][j - w[i]] + v[i]);
				} else
					dp[i % 3][j] = max(dp[i % 3][j - 1], dp[i % 3][j - 1] + v[i]);
			}
		}
		cout << dp[3][n / 2] + dp[2][n / 2] + dp[1][n / 2] << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}