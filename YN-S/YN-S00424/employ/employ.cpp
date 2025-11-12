// file memory long long
// 16点35分 20pts

#include <bits/stdc++.h>

bool st;
int dp[300010][20]; // 面试了 S 中的人，录取了 i 人的方案数
char ch[510];
int c[510];
bool en;

const int mod = 998244353;

int main()
{
//	fprintf(stderr, "%.1lf", (&en - &st) / 1024.0 / 1024.0); // 22.9 MB

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;

	scanf("%d %d", &n, &m);
	scanf("%s", ch + 1);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}

	int N = (1 << n) - 1;

	dp[0][0] = 1;
	for (int S = 0; S <= N; S++)
	{
		for (int i = 0; i <= n; i++)
		{
			int d = __builtin_popcount(S);

//			printf("%d ", dp[S][i]);

			if (dp[S][i] == 0)
			{
				continue;
			}

			for (int k = 1; k <= n; k++)
			{
				if (!(S & (1 << (k - 1))))
				{
					if (d - i < c[k] && ch[d + 1] == '1')
					{
						dp[S | (1 << (k - 1))][i + 1] = (dp[S | (1 << (k - 1))][i + 1] + dp[S][i]) % mod;
					}
					else
					{
						dp[S | (1 << (k - 1))][i] = (dp[S | (1 << (k - 1))][i] + dp[S][i]) % mod;
					}
				}
			}
		}
//		printf("\n");
	}

	int ans = 0;

	for (int i = m; i <= n; i++)
	{
		ans = (ans + dp[N][i]) % mod;
	}

	printf("%d", ans);

	return 0;
}
