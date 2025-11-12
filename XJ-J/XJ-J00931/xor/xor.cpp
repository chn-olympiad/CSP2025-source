#include <bits/stdc++.h>
using namespace std;
int sx[500010],dp[500010];
int a[500010];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sx[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sx[i]=(sx[i-1]^a[i]);
	}
	int pos=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=i;j>=pos;j--)
		{
			if((sx[i]^sx[j-1])==k)  {
				dp[i]=max(dp[j-1]+1,dp[i]);
				pos=j;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
