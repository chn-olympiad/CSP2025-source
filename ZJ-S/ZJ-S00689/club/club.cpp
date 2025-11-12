#include <bits/stdc++.h>
const int N = 35;

int n, dp[N][N >> 1][N >> 1][N >> 1];
//std::vector<std::tuple<int, int, int> > a;
int a[N][4], tmp[N];

inline void solve()
{
	std::cin >> n; int t = (n >> 1); bool flag = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
		{
			std::cin >> a[i][j];
			if (a[i][2] != 0 || a[i][3] != 0) flag = 1;
		}
	if (!flag)
	{
		for (int i = 1; i <= n; ++i) tmp[i] = a[i][1];
		std::sort(tmp + 1, tmp + 1 + n, std::greater<int>());
		int sum = 0;
		for (int i = 1; i <= t; ++i) sum += tmp[i];
		std::cout << sum << '\n';
		return ;
	}
	for (int step = 1; step <= n; ++step)
		for (int i = 1; i <= t; ++i)
			for (int j = 1; j <= t; ++j)
				for (int k = 1; k <= t; ++k)
					dp[step][i][j][k] = 0;
	for (int step = 1; step <= n; ++step)
		for (int i = 0; i <= t; ++i)
			for (int j = 0; j <= t; ++j)
				for (int k = 0; k <= t; ++k)
				{
					if (i == 0) 
					{
						if (j == 0 && k == 0) continue;
						if (j == 0) { dp[step][i][j][k] = dp[step - 1][i][j][k - 1] + a[step][3]; continue; }
						if (k == 0) { dp[step][i][j][k] = dp[step - 1][i][j - 1][k] + a[step][2]; continue; }
						dp[step][i][j][k] = std::max(dp[step - 1][i][j - 1][k] + a[step][2], dp[step - 1][i][j][k - 1] + a[step][3]);
						continue;
					}
					if (j == 0) 
					{
						if (i == 0 && k == 0) continue;
						if (i == 0) { dp[step][i][j][k] = dp[step - 1][i][j][k - 1] + a[step][3]; continue; }
						if (k == 0) { dp[step][i][j][k] = dp[step - 1][i - 1][j][k] + a[step][1]; continue; }
						dp[step][i][j][k] = std::max(dp[step - 1][i - 1][j][k] + a[step][1], dp[step - 1][i][j][k - 1] + a[step][3]);
						continue;
					}
					if (k == 0) 
					{
						if (j == 0 && i == 0) continue;
						if (j == 0) { dp[step][i][j][k] = dp[step - 1][i - 1][j][k] + a[step][1]; continue; }
						if (i == 0) { dp[step][i][j][k] = dp[step - 1][i][j - 1][k] + a[step][2]; continue; }
						dp[step][i][j][k] = std::max(dp[step - 1][i][j - 1][k] + a[step][2], dp[step - 1][i - 1][j][k] + a[step][1]);
						continue;
					}
					dp[step][i][j][k] = std::max({dp[step - 1][i - 1][j][k] + a[step][1],
												 dp[step - 1][i][j - 1][k] + a[step][2],
												 dp[step - 1][i][j][k - 1] + a[step][3]});
				}
	int ans = 0;
	for (int i = 1; i <= t; ++i)
		for (int j = 1; j <= t; ++j)
			for (int k = 1; k <= t; ++k)
				ans = std::max(ans, dp[n][i][j][k]);
	std::cout << ans << '\n';
}

signed main()
{
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}