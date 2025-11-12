#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;

int a[maxn][5];
int dp[maxn][maxn][maxn];
// Ren5Jie4Di4Ling5%
int ch[maxn];

void solveB(int n)
{
	for(int i = 1; i <= n; i++)
		ch[i] = a[i][2] - a[i][1];
	sort(ch + 1, ch + n + 1, greater<int>());
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i][1];
	for(int i = 1; i <= n / 2; i++)
		ans += ch[i];
	cout << ans << endl;
}

void solve()
{
	int n;
	cin >> n;
	bool B = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		B &= a[i][3] == 0;
	}
	if(B)
	{
		solveB(n);
		return;
	}
	for(int i = 0; i <= n / 2; i++)
		for(int j = 0; j <= n / 2; j++)
			for(int k = 0; k <= n / 2; k++)
				if(i + j + k < n)
				{
					if(i < n / 2)
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + a[i + j + k + 1][1]);
					if(j < n / 2)
						dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + a[i + j + k + 1][2]);
					if(k < n / 2)
						dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k] + a[i + j + k + 1][3]);
				}
	int ans = 0;
	for(int i = 0; i <= n / 2; i++)
		for(int j = 0; j <= n / 2; j++)
			if(i + j >= n / 2)
				ans = max(ans, dp[i][j][n - i - j]);
	cout << ans << endl;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		solve();
	}
	return 0;
}
