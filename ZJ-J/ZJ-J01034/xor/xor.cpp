#include <cstdio>
#include <iostream>
using namespace std;

struct Node
{
	long long l,r;
}ans[1000000];
long long n,k,a[1000000],sum[1000000],cnt,dp[1000000],maxn;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if((sum[j]^sum[i-1]) == k)
			{
				cnt ++;
				ans[cnt].l = i,ans[cnt].r = j;
				break;
			}
		}
	}
	for(int i = 1;i <= cnt;i ++)
	{
		dp[i] = 1;
		for(int j = i-1;j >= 1;j --)
		{
			if(ans[j].r < ans[i].l)
			{
				dp[i] = max(dp[i],dp[j]+1);
				break;
			}
		}
		maxn = max(maxn,dp[i]);
	}
	cout << maxn;
	return 0;
}