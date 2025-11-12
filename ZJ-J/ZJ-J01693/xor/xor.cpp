#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],dp[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=(sum[i-1]^a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n];
return 0;
}
