#include	<algorithm>
#include	<iostream>
#include	<cstring>
#include	<vector>
#include	<cmath>
#define		int		long long
using namespace std;
constexpr int maxn = 1e5+4;
constexpr int _maxn = 204;

int t, n;
int cnt[4];
int b[maxn];
int a[maxn][4];
int dp[_maxn][_maxn][_maxn];

signed main (void)
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
				scanf ("%lld", &a[i][j]);
		}
		if (n <= 10)
		{
			int ans = 0;
			int tot = 0;
			for (int st = pow (3, n) - 1; ~st; st--)
			{
				int x = st;
				int sum = 0;
				memset (cnt, 0, sizeof cnt);
				for (int i = 1; i <= n; i++, x /= 3)
				{
					sum += a[i][x % 3 + 1];
					cnt[x % 3 + 1]++;
				}
				if (cnt[1] > n / 2 || cnt[2] > n / 2 || cnt[3] > n / 2)
					continue;
				else
				{
					ans = max (ans, sum);
					tot++;
				}
			}
			// cout << tot << endl;
			cout << ans << endl;
		}
		else if ([&] ()
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i][2] || a[i][3])
					return 0;
			}
			return 1;
		}())			// Constraint A
		{
			for (int i = 1; i <= n; i++)
				b[i] = a[i][1];
			sort (b + 1, b + n + 1, greater<int> ());
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += b[i];
			cout << ans << endl;
		}
		else if ([&] ()
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i][3])
					return 0;
			}
			return 1;
		}())			// Constraint B
		{
			int ans = 0;
			vector<int> vec;
			for (int i = 1; i <= n; i++)
			{
				ans += a[i][1];
				vec.emplace_back(a[i][2] - a[i][1]);
			}
			sort (vec.rbegin(), vec.rend());
			for (int i = 0; i < n / 2; i++)
				ans += vec[i];
			cout << ans << endl;
		}
		else
		{
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= n; j++)
					memset (dp[i][j], 0, (n + 1) * sizeof (int));
			}
			int ans = 0;
			for (int i = 0; i <= n / 2; i++)
			{
				for (int j = 0; j <= n / 2 && i + j <= n; j++)
				{
					for (int k = 0; k <= n / 2 && i + j + k <= n; k++)
					{
						if (i)
							dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k] + a[i + j + k][1]);
						if (j)
							dp[i][j][k] = max (dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][2]);
						if (k)
							dp[i][j][k] = max (dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][3]);
						if (i + j + k == n)
							ans = max (ans, dp[i][j][k]);
						// cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
					}
				}
			}
			cout << ans << endl;
		}
		// else
		// {
		// 	/**
		// 	 * 先全部钦定选择第 1 个部门
		// 	 * 记录转 2 和转 3 的代价，并按二者最大值降序排序
		// 	*/
		// }
	}
	return 0;
}
