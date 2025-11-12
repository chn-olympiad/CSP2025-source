#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], sum[500005], dp[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sum[1] = a[1];
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] ^ a[i];
	{
		dp[i] = dp[i - 1];
		if (sum[i] == k)
			dp[i] = max(dp[i], 1LL);
		for (int j = i; j >= 2; j--)
		{
			if (dp[i] > dp[j - 1])
				break;
			long long tmp = sum[i] ^ sum[j - 1];
			if (tmp == k)
				dp[i] = max(dp[i], dp[j - 1] + 1);
		}
	}
	cout << dp[n];
	return 0;
}