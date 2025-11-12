#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		if(!dp[i])dp[i]=max(dp[i],dp[i-1]);
		for(int j=i;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				if(dp[j]==dp[j-1])dp[j]=max(dp[j],max(dp[i-1],dp[i]+1));
				break;
			}
		}
	}
	sort(dp+1,dp+n+1);
	cout<<dp[n];
	return 0;
}
