#include <bits/stdc++.h>
using namespace std;

int n, a1[100003], a2[100003], a3[100003], dp[203][203][203], maxn = 0;
int num[4], max2 = 0, max3 = 0;

void f(int x, int sum)
{
	if (num[1] > n / 2 || num[2] > n / 2 || num[3] > n / 2) return;
	if (x > n)
	{
		maxn = max(maxn, sum);
		return;
	}
	num[1]++;
	f(x + 1, sum + a1[x]);
	num[1]--;
	num[2]++;
	f(x + 1, sum + a2[x]);
	num[2]--;
	num[3]++;
	f(x + 1, sum + a3[x]);
	num[3]--;
	return;
}

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			max2 = max(max2, a2[i]);
			max3 = max(max3, a3[i]);
		}
		memset(dp, 0, sizeof(dp));
		if (n <= 30)
		{
			maxn = 0;
			f(1, 0);
			printf("%d\n", maxn);
		}
		else if (n <= 200)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					for(int k = 1; k <= n; k++)
					{
						for(int p = n; p >= 1; p--)
						{
							dp[i][j][k] = max(max(max(dp[i][j][k], dp[i - 1][j][k] + a1[p]), dp[i][j - 1][k] + a2[p]), dp[i][j][k - 1] + a3[p]);
						}
					}
				}
			}
			printf("%d\n", dp[n / 2][n / 2][n / 2]);
		}
		else
		{
			if (max2 == 0 && max3 == 0)
			{
				sort(a1 + 1, a1 + n + 1, cmp);
				long long sum = 0;
				for(int i = 1; i <= n / 2; i++)
				{
					sum += a1[i];
				}
				cout << sum << "\n";
				continue;
			}
			
		}
	}
	return 0;
}
