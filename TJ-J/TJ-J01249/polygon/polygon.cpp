#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353ll;

long long a[5001];
long long sum[5001];
long long dp[25000001] = {0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(long long i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	long long res = 0;
	for(long long i = 1;i < n;i++)
	{
		for(long long j = sum[i];j >= a[i];j--)
		{
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		}
		dp[a[i]] = (1 + dp[a[i]]) % mod;
		for(long long j = a[i + 1] + 1;j <= sum[i];j++)
		{
			res = (res + dp[j]) % mod;
		}
	} 
	cout << res;
	return 0;
}
