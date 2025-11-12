#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5010;
int n,a[N],w;
long long dp[2][N],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);w=a[n];
	dp[1][a[1]]=1ll;
    for(int i=2;i<=n;i++)
    {
    	if(i>=3)
    	{
    		long long s=0;
    		for(int j=w+1;j>a[i];j--) s=(s+dp[i-1&1][j])%mod;
    		ans=(ans+s)%mod;
		}
	    for(int j=1;j<=w+1;j++)
	    {
	    	if(a[i]==j) dp[i&1][j]=(dp[i&1][j]+1ll)%mod;
	      	dp[i&1][j]=(dp[i&1][j]+dp[i-1&1][j])%mod;
	      	if(j+a[i]<=w) dp[i&1][j+a[i]]=(dp[i&1][j+a[i]]+dp[i-1&1][j])%mod;
	      	else dp[i&1][w+1]=(dp[i&1][w+1]+dp[i-1&1][j])%mod;
		}
		for(int j=1;j<=w+1;j++) dp[i-1&1][j]=0;
	}
    cout<<ans;
	return 0;
}