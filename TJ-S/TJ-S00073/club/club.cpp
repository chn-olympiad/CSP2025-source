#include <bits/stdc++.h>
using namespace std;

long long n, t, ans, maxn;
long long a[100010][3], cnt[3], times[100010];

void solve(long long time)
{
	for (long long i = 0; i < 3; i++)
	{
		times[time] = i;
		if (time == 1)
		{
			memset(cnt, 0, sizeof(cnt));
			bool skip = 0;
			for (long long j = time; j <= n; j++)
			{
				if (cnt[times[j]] == maxn)
				{
					skip = 1;
					continue;
				}
				cnt[times[j]]++;
			}
			if (skip)
			{
				continue;
			}
			long long sum = 0;
			for (long long j = time; j <= n; j++)
			{
				sum += a[j - 1][times[j]];
			}
			ans = max(ans, sum);
		}
		else
		{
			solve(time - 1);
		}
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &t);
	while (t--)
	{
		ans = 0;
		scanf("%lld", &n);
		maxn = n / 2;
		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < 3; j++)
			{
				scanf("%lld", &a[i][j]);
			}
		}
		
		solve(n);
		
		printf("%lld\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
