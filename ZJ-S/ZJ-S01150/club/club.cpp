#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int T, n, ans;
/*
void dfs(int step, int sum, int aa, int b, int c)
{
	if (step > n)
	{
		ans = max(ans, sum);
		return ;
	}
	
	if (aa + 1 <= n / 2)
		dfs(step + 1, sum + a[step][0], aa + 1, b, c);
	if (b + 1 <= n / 2)
		dfs(step + 1, sum + a[step][1], aa, b + 1, c);
	if (c + 1 <= n / 2)
		dfs(step + 1, sum + a[step][2], aa, b, c + 1);
}
*/
struct node
{
	int c[3], val;
};
struct aa
{
	int c[3];
}a[MAXN];
node dp[MAXN][3];
bool cmp(aa a, aa b)
{
	if (a.c[0] != b.c[0]) return a.c[0] > b.c[0];
	if (a.c[1] != b.c[1]) return a.c[1] > b.c[1];
	return a.c[2] > b.c[2];
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i].c[j];
		for (int i = 0; i < MAXN; i++)
		{
			for (int k = 0; k <= 3; k++)
			{
				dp[i][k].val = 0;
				for (int j = 0; j < 3; j++)
					dp[i][k].c[j] = 0;
			}
		}
		//dfs(1, 0, 0, 0, 0);
		/*
		sort(a + 1, a + n + 1, cmp);
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << a[i].c[j] << " ";
			cout << "\n";
		}
			
		*/
		for (int i = 1; i <= n; i++)
			for (int k = 0; k < 3; k++)
				for (int j = 0; j < 3; j++)
					if (dp[i - 1][k].c[j] + 1 <= n / 2)
					{
						if (dp[i][k].val < dp[i - 1][j].val + a[i].c[k])
						{
							dp[i][k].val = dp[i - 1][j].val + a[i].c[k];
							dp[i][k].c[0] = dp[i - 1][j].c[0];
							dp[i][k].c[1] = dp[i - 1][j].c[1];
							dp[i][k].c[2] = dp[i - 1][j].c[2];
							dp[i][k].c[k]++;
						}
					}
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << dp[i].val << " ";
			cout << "\n";
		}
		*/
		cout << max(dp[n][0].val, max(dp[n][1].val, dp[n][2].val)) << endl;
	}
	return 0;
}
