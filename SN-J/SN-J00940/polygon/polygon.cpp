//SN-J00940 ΩØ”ÍÍÿ 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 5005 
#define mod 998244353 
using namespace std;
ll n,a[maxn],dp[maxn][maxn],ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); dp[0][0]=1;
	for(int i=0;i<n;i++) for(int j=0;j<=5001;j++)
	{
		dp[i+1][j]+=dp[i][j]; if(dp[i+1][j]>=mod) dp[i+1][j]-=mod;
		dp[i+1][min(j+a[i+1],5001LL)]+=dp[i][j];
		if(dp[i+1][min(j+a[i+1],5001LL)]>=mod) dp[i+1][min(j+a[i+1],5001LL)]-=mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=5001;j++)
		{
			ans+=dp[i-1][j]; if(ans>=mod) ans-=mod;
		}
	}
	cout<<ans;
	return 0;
}
