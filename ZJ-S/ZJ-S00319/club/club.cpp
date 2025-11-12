#include <bits/stdc++.h>
using namespace std;
int dp[205][205][205];
int a[100005][3];
int b[100005];
void A(int n)
{
	for (int i = 1; i <= n; i++)
		b[i] = a[i][0];
	sort(b + 1, b + 1 + n, greater<int>());
	int ans = 0;
	for (int i = 1; i <= n / 2; i++)
		ans += b[i];
	cout << ans;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof dp);
		int n, ans = 0;
		bool t1 = 1, t2 = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][1])
				t1 = 0;
			if (a[i][2])
				t2 = 0;
		}
		if (t1 && t2)
		{
			A(n);
			continue;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= min(i, n / 2); j++)
				for (int k = 0; k <= min(i, n / 2); k++)
				{
					int p = i - j - k;
					if (p > n / 2)
						continue;
					if (j)
						dp[j][k][p] = max(dp[j][k][p], dp[j - 1][k][p] + a[i][0]);
					if (k)
						dp[j][k][p] = max(dp[j][k][p], dp[j][k - 1][p] + a[i][1]);
					if (p)
						dp[j][k][p] = max(dp[j][k][p], dp[j][k][p - 1] + a[i][2]);
				}
		for (int i = 0; i <= n / 2; i++)
			for (int j = 0; j <= n / 2; j++)
				ans = max(ans, dp[i][j][n - i - j]);
		cout << ans << "\n";
	}
	return 0;
}
