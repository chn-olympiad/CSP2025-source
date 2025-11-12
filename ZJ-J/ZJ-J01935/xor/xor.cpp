#include<bits/stdc++.h>
using namespace std;
int n,a[500007],k,dp[500007];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int an;
		for(int j=i;j<=n;j++)
		{
			if(j==i) an=a[i];
			else an=an^a[j];
			if(an==k)
			{
				dp[j]=i;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dp[i]) dp[i]=dp[dp[i]-1]+1;
		dp[i]=max(dp[i-1],dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
