#include <bits/stdc++.h>

const int maxn = 256;

int t, n, a[maxn][12];
int dp[maxn][maxn][maxn];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	std::cin >> t;
	
	while (t -- ) {
		std::cin >> n;
		
		if (n <= 200) {
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= 3; j++)
					std::cin >> a[i][j];
				
			memset(dp, 0xAC, sizeof(dp));
			dp[0][0][0] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j <= i; j++)
					for (int k = 0; j + k <= i; k++) {
						dp[i][j][k] = dp[i - 1][j][k] + a[i][1];
						if (j) dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][2]);
						if (k) dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][3]);
					}
			
			int ans = 0;
			for (int j = 0; j <= n / 2; j++)
				for (int k = 0; k <= n / 2; k++)
					if (n - j - k <= n / 2)
						ans = std::max(ans, dp[n][j][k]);
		
			std::cout << ans << "\n";
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int x, y, z;
				std::cin >> x >> y >> z;
				ans += std::max(x, std::max(y, z));
			}
			std::cout << ans << "\n";
		}
	}	
	
	return 0;
}
