#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[5005][5005];
ll a[5005];
const ll mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;ll cnt=0;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=5001;i++) dp[0][i]=0;
	dp[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<=5001;j++)
		{
			if(j>=a[i]){
				dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
				if(j>a[i])cnt+=dp[i-1][j];cnt%=mod;
			}
			else dp[i][j]=dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	cout<<cnt;
	return 0;
	//haha 11:06 AC all
}