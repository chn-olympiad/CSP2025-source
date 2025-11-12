#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
typedef long long ll;
const int N = 1e5 + 10;
const int M = 2e2 + 10;
const int K = 40;

int ccnt;
bool vis[N];
int tot[4];
int doit[N];
int a[N][4];
ll f[M][M][M];
ll dp[K][K][K][K];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= 3; ++j)
				cin >> a[i][j];
		}
		if (n <= 30)
		{
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= 3; ++j)
				{
					if (j == 1)
					{
						for (int k = n / 2 - 1; k >= 0; --k)
						{
							for (int l = n / 2; l >= 0; --l)
							{
								for (int m = std::min(n / 2, i - l - k - 1); m >= 0; --m)
									dp[i][k + 1][l][m] = std::max(dp[i][k + 1][l][m], dp[i - 1][k][l][m] + a[i][j]);
							}
						}
					}
					if (j == 2)
					{
						for (int k = n / 2; k >= 0; --k)
						{
							for (int l = n / 2 - 1; l >= 0; --l)
							{
								for (int m = std::min(n / 2, i - l - k - 1); m >= 0; --m)
									dp[i][k][l + 1][m] = std::max(dp[i][k][l + 1][m], dp[i - 1][k][l][m] + a[i][j]);
							}
						}
					}
					if (j == 3)
					{
						for (int k = n / 2; k >= 0; --k)
						{
							for (int l = n / 2; l >= 0; --l)
							{
								for (int m = std::min(n / 2 - 1, i - l - k - 1); m >= 0; --m)
									dp[i][k][l][m + 1] = std::max(dp[i][k][l][m + 1], dp[i - 1][k][l][m] + a[i][j]);
							}
						}
					}
				}
			}
			ll ans = 0;
			for (int i = 0; i <= n / 2; ++i)
			{
				for (int j = 0; j <= n / 2; ++j)
				{
					for (int k = 0; i + j + k <= n && k <= n / 2; ++k)
						ans = std::max(ans, dp[n][i][j][k]);
				}
			}
			cout << ans << '\n';
			continue;
		}
		else if (n <= 200)
		{
			memset(f, 0, sizeof(f));
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= 3; ++j)
				{
					if (j == 1)
					{
						for (int k = n / 2 - 1; k >= 0; --k)
						{
							for (int l = n / 2; l >= 0; --l)
								f[i][k + 1][l] = std::max(f[i][k + 1][l], f[i - 1][k][l] + a[i][j]);
						}
					}
					if (j == 2)
					{
						for (int k = n / 2; k >= 0; --k)
						{
							for (int l = n / 2 - 1; l >= 0; --l)
								f[i][k][l + 1] = std::max(f[i][k][l + 1], f[i - 1][k][l] + a[i][j]);
						}
					}
					if (j == 3)
					{
						for (int k = n / 2; k >= 0; --k)
						{
							for (int l = n / 2 - 1; l >= 0; --l)
								f[i][k][l] = std::max(f[i][k][l], f[i - 1][k][l]);
						}
					}
				}
			}
			ll ans = 0;
			for (int i = 0; i <= n / 2; ++i)
			{
				for (int j = 0; j <= n / 2; ++j)
					ans = std::max(ans, f[n][i][j]);
			}
			cout << ans << '\n';
			continue;
		}
		ll ans = 0;
		ccnt = 0;
		for (int i = 1; i <= n; ++i)
			doit[++ccnt] = a[i][1];
		std::sort(doit + 1, doit + ccnt + 1, [&](const int &a, const int &b){return a > b;});
		for (int i = 1; i <= n / 2; ++i)
			ans += doit[i];
		cout << ans << '\n';
	}
	return 0;
}
