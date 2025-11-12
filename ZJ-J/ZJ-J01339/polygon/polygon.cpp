#include <iostream>
#include <algorithm>
#include <cstdio>
#define mod 998244353
using namespace std;

int n,m,a[5010];
long long ans,dp[2][5010];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]),m = max(m,a[i]);
	sort(a + 1,a + n + 1);
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m + 1;j++) dp[i & 1][j] = dp[!(i & 1)][j];
		for (int j = a[i] + 1;j <= m + 1;j++) (ans += dp[i & 1][j]) %= mod;
		for (int j = 0;j <= m + 1;j++) (dp[i & 1][min(j + a[i],m + 1)] += dp[!(i & 1)][j]) %= mod;
	}
	printf("%lld\n",ans);
	return 0;
} 
