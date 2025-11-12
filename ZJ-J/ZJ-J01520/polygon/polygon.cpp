#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int dp[25000005],n,a[5005],f[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=f[i];j>=a[i];j--)
		{
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			if(i>=2&&j>a[i+1])ans=(ans+dp[j])%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//CSP RP++
