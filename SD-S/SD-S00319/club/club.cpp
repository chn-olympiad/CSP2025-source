#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N][10], b[N], dp[210][110];
int n, ans;

void dfs(int step, int sum, int cnt1, int cnt2, int cnt3)
{
	if (step > n)	
	{
		ans = max(ans, sum);
		return;
	}
	if (cnt1 < n / 2) dfs(step + 1, sum + a[step][1], cnt1 + 1, cnt2, cnt3);
	if (cnt2 < n / 2) dfs(step + 1, sum + a[step][2], cnt1, cnt2 + 1, cnt3);
	if (cnt3 < n / 2) dfs(step + 1, sum + a[step][3], cnt1, cnt2, cnt3 + 1);
}

bool cmp(int A, int B)
{
	return A > B;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		bool flaga = true, flagb = true;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) flaga = false;
			if (a[i][3] != 0) flagb = false;
		}
		if (flaga)
		{
			for (int i = 1; i <= n; i++)
			{
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1, cmp);
			int sum = 0;
			for (int i = n; i > n / 2; i--)
			{
				sum += b[i];
			}
			cout << sum << endl;
			continue;
		}
		if (flagb)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = n / 2; j >= n / 2 - i; j--)
				{
					dp[i][j] = max(dp[i - 1][j] + a[i][2], dp[i][j]);
					if (j != 0) dp[i][j - 1] = dp[i - 1][j] + a[i][1];
				}
			}
			int maxn = -1e9;
			for (int i = 0; i <= n / 2; i++) maxn = max(maxn, dp[n][i]);
			cout << maxn << endl;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
