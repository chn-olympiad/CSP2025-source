#include <bits/stdc++.h>
#define max(x, y, z) std::max(x, std::max(y, z))
constexpr unsigned long long N = 1e5 + 3;
unsigned long long dp[4][N];
unsigned long long a[4][N];

bool cmp(
	unsigned long long x, unsigned long long y
) {return x > y;}

int main () 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		short sp_a = 1, sp_b = 1;
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) 
		{
			scanf("%lld%lld%lld", &a[1][i], &a[2][i], &a[3][i]);
			if (a[2][i] != 0) sp_a = 0;
			if (a[3][i] != 0) sp_a = 0, sp_b = 0;
		}

		if (sp_a)
		{
			std::sort(a[1] + 1, a[1] + n + 1, cmp);
			unsigned long long sum = 0;
			for (int i=1; i<=(n >> 1); ++i) sum += a[1][i];
			printf("%lld\n", sum);
			continue;
		}
		for (int i=1; i<=n; ++i)
		{
			unsigned long long m = max(dp[1][i-1], dp[2][i-1], dp[3][i-1]);
			for (int j=1; j<=3; ++j)
			{
				dp[j][i] = m + a[j][i];
			}
		}
		printf("%lld\n", max(dp[1][n], dp[2][n], dp[3][n]));
	}
}
