// file memory long long
// 15点32分 60pts
// 17点57分 60pts+（如果没有多测应该能骗一点）

#include <bits/stdc++.h>

using namespace std;

bool st;
int n;
long long a[100010][4];
long long b[100010];
long long dp[210][110][110];

namespace _55pts
{
	long long solve()
	{
		memset(dp, -0x3fll, sizeof(dp));

		dp[0][0][0] = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n / 2; j++)
			{
				for (int k = 0; k <= n / 2; k++)
				{
					if (j + 1 <= n / 2)
					{
						dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[i + 1][1]);
					}
					if (k + 1 <= n / 2)
					{
						dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[i + 1][2]);
					}
					if (i - j - k + 1 <= n / 2)
					{
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + a[i + 1][3]);
					}
				}
			}
		}

		long long ans = 0;

		for (int j = 0; j <= n / 2; j++)
		{
			for (int k = 0; k <= n / 2; k++)
			{
				if (n - j - k <= n / 2)
				{
					ans = max(ans, dp[n][j][k]);
				}
			}
		}

		return ans;
	}
};

struct P
{
	long long val;
	int i, j;

	bool operator < (P b) const
	{
		return val > b.val;
	}

	bool operator > (P b) const
	{
		return val < b.val;
	}
};

int vis[100010];

bool cmp(int i, int j)
{
	return max({a[i][1], a[i][2], a[i][3]}) > max({a[j][1], a[j][2], a[j][3]});
}

namespace _100pts
{
	long long solve()
	{
		long long ans = 0;
		priority_queue<P> M[4];
		priority_queue<P, vector<P>, greater<P>> Q;

		memset(vis, 0, sizeof(vis));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				Q.push({a[i][j], i, j});
			}
		}

		while (!Q.empty())
		{
			int i = Q.top().i, j = Q.top().j;
			Q.pop();

			if (vis[i] == true)
			{
				continue;
			}

			if ((int)M[j].size() + 1 <= n / 2)
			{
				vis[i] = true;
				M[j].push({a[i][j], i, j});
				ans = ans + a[i][j];
			}
			else if (!M[j].empty())
			{
				int pos = 0, l = M[j].top().i;
				long long nxt = 0;

				bool OK = false;
				for (int y = 1; y <= 3; y++)
				{
					if (y != j && (int)M[y].size() + 1 <= n / 2 && a[i][y] == a[i][j])
					{
						OK = true;
					}
				}

				if (OK == true)
				{
					continue;
				}

				for (int y = 1; y <= 3; y++)
				{
					if (nxt < a[l][y] && y != j && (int)M[y].size() + 1 <= n / 2)
					{
						nxt = a[l][y];
						pos = y;
					}
				}

				if (ans + a[i][j] + a[l][pos] - M[j].top().val >= ans)
				{
					ans = ans + a[i][j] + a[l][pos] - M[j].top().val;
					vis[i] = true;
					Q.push(M[j].top());
					M[j].pop();
					M[j].push({a[i][j], i, j});
					M[pos].push({a[l][pos], l, pos});
				}
			}
		}

		return ans;
	}
};

bool en;

int main()
{
//	fprintf(stderr, "%.1lf", (&en - &st) / 1024.0 / 1024.0); // 23.6 MB

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		bool flagA = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld %lld %lld", &a[i][1], &a[i][2], &a[i][3]);
			flagA &= a[i][2] == 0 && a[i][3] == 0;
		}

		if (flagA == true) // 5pts
		{
			for (int i = 1; i <= n; i++)
			{
				b[i] = a[i][1];
			}

			sort(b + 1, b + n + 1, greater<long long>());

			long long ans = 0;
			for (int i = 1; i <= n / 2; i++)
			{
				ans += b[i];
			}

			printf("%lld", ans);
		}
		else if (n <= 200) // 55pts
		{
			printf("%lld\n", _55pts::solve());
		}
		else
		{
			printf("%lld\n", _100pts::solve()); // 反悔贪心？错的！
		}
	}

	return 0;
}
/*
Hack：

1
4
10 9 8
4 6 0
5 7 0
1 3 3
*/