#include <bits/stdc++.h>
using namespace std;
long long n, k, a, ans, now = -1;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		if (now == -1)
		{
			now = a;
		}
		else
		{
			now ^= a;
		}
		if (now == k)
		{
			ans++;
			now = -1;
		}
	}
	printf("%lld", ans);
	return 0;
}

