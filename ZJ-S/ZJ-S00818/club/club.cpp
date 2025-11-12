#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10, M = 210;
int n, dp[M][M][M];
struct Node
{
	int d[3];
	int operator [] (const int i) const {return d[i];}
} a[N];
int c[N];
void solve()
{
	int ans = 0;
	cin >> n;
	bool opt1 = 0, opt2 = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i].d[0] >> a[i].d[1] >> a[i].d[2];
		opt1 &= (a[i][1] == a[i][2] && a[i][1] == 0);
		opt2 &= (a[i][2] == 0);
	}
	if(n <= 200)
	{
		memset(dp, -0x3f, sizeof dp);
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 0; j <= (n / 2); j ++)
			{
				for(int k = 0; k <= min((n / 2), n - j); k ++)
				{
					if(j >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][0]);
					if(k >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][1]);
					if(j + k < n) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][2]);
				}
			}
		}
		for(int j = 0; j <= (n / 2); j ++)
		{
			for(int k = 0; k <= (n / 2); k ++)
			{
				if(n - j - k > (n / 2)) continue;
				ans = max(dp[n][j][k], ans);
			}
		}
	}else if(opt1)
	{
		for(int i = 1; i <= n; i ++) c[i] = a[i][0];
		sort(c + 1, c + n + 1, greater<int>());
		for(int i = 1; i <= (n / 2); i ++) ans += c[i];
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}

