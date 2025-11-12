#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int n, a[5005];
long long ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (long long i = 7; i < (1 << n); i++)
	{
		int k = i, sum = 0, cnt = 1, Max = 0;
		while (k)
		{
			if (k & 1)
			{
				Max = a[cnt];
				sum += a[cnt];
			}
			cnt++;
			k >>= 1;
		}
		if (sum > (Max << 1))
		{
			ans++;
		}
		if (ans == mod) ans = 0;
	}
	printf("%lld\n", ans);
	return 0;
}
