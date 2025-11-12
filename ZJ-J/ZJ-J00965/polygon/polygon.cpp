#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
const long long mod = 998244353;
long long n;
long long sum;
long long a[5005];
long long dp[25000005];
int main()
{
	long long ans = 0;
	fre();
	cin>>n;
	for(long long i = 1; i<=n; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	dp[0] = 1;
	for(long long i = 1; i<=n; i++)
	{
		long long tmp = a[i]*2+1;
		if(i>=3)
		{
			for(long long j = a[i]+1; j<=sum; j++)
			{
				ans+=dp[j];
				ans%=mod;
			}
		}
		for(long long j = sum-a[i]; j>=0; j--)
		{
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=mod;
		}
	}
	cout<<ans;
	return 0;
}
