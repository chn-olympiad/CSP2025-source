#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=998244353;
int n,k;
int a[N];
long long dp[N][4];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=0;
	int mx=5001;
	for(int i=1;i<=n;i++)
	{
		int mn=a[i];
		long long res=0;
		for(int j=mn+1;j<=5001;j++)
		{
			res+=(dp[j][2]+dp[j][3])%mod;
			res%=mod;
		}
		ans+=res;
		ans%=mod;
		long long ppp=0;
		for(int j=5001;j>=5001-a[i];j--)
		{
			ppp=(ppp+dp[j][3])%mod;
			ppp=(ppp+dp[j][2])%mod;
		}
		dp[5001][3]+=ppp;
		dp[5001][3]%=mod;
		for(int j=5000;j>a[i];j--)
		{
			dp[j][3]=(dp[j][3]+dp[j-a[i]][3])%mod;
			dp[j][3]=(dp[j][3]+dp[j-a[i]][2])%mod;
			dp[j][3]%=mod;
		}
		dp[a[i]][1]=(dp[a[i]][1]+1)%mod;
		for(int j=1;j<i;j++)
		{
			int d=min(5001,a[i]+a[j]);
			dp[d][2]=(dp[d][2]+1)%mod;
		}
	}
	cout<<ans;
	return 0;
}
