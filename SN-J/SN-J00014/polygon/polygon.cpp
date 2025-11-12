#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans=0;
long long dp[5005];
long long pw[5005];
long long mo=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	pw[0]=1;
	for(long long i=1;i<n;i++)
	{
		pw[i]=(pw[i-1]*2)%mo;
	}
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(long long i=1;i<=n;i++)
	{
		long long cnt=0;
		for(long long j=0;j<=a[i];j++)
		{
			cnt+=dp[j];
			cnt%=mo;
		}
		for(long long j=a[n];j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
			dp[j]%=mo;
		}
		ans+=(pw[i-1]+mo-cnt)%mo;
		ans%=mo;
	}
	cout<<ans<<endl;
	return 0;
}
