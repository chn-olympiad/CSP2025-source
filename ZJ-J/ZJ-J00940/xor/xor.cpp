#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500100],dp[500100];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x=i,now=a[i];
		dp[i]=dp[i-1];
		while(now!=k&&x>1&&dp[x-1]+1>dp[i-1])
		{
			x--;
			now=now^a[x];
		}
		if(now==k) dp[i]=max(dp[i-1],dp[x-1]+1);
	}
	cout<<dp[n];
	return 0;
}
