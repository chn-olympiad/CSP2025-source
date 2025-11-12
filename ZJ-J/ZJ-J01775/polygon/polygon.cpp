#include<bits/stdc++.h>
using namespace std;
int n,mod=998244353,sum,a[5005],t[5005],dp[5005][5005];
long long calc(int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	return ans;
}
long long h(int m,int n)
{
	return calc(n)/(calc(m)*calc(n-m));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]==a[1])
	{
		int sum=0;
		for(int i=3;i<=n;i++)
			sum=(sum+h(i,n))%mod;
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]+a[i];
	for(int l=3;l<=n;l++)
	{
		int maxl=2*a[l],suml=t[l];
		if(suml<=maxl) continue;
		dp[l][l]=1;
		for(int i=3;i<l;i++)
		{
			if(dp[l-1][i]==0&&i==3&&l==2)
			{
				int cnt=0;
				for(int j=1;j<l;j++)
				{
					if(suml-a[j]<=maxl) break;
					cnt++;
				}
				dp[l][i]=cnt;
			}
			else if(dp[l-1][i]==0&&i==3) dp[l][i]=dp[l-1][i]+1;
			else if(dp[l-1][i]==0) dp[l][i]=dp[l][i-1]+l-i+1;
			else dp[l][i]=dp[l-1][i]+dp[l][i-1]+1;
		}
	}
	for(int i=3;i<=n;i++)
		for(int j=3;j<=i;j++)
			sum=(sum+dp[i][j])%mod;
	printf("%d",sum%mod);
	return 0;
}