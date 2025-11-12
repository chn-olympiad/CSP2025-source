#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],s[500001],dp[500001],l=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int pp=s[i]^k;
		for(int j=l+1;j<=i;j++)
		{
			if(pp==s[j-1])
			{
				dp[i]=dp[j-1]+1;
				l=i;
				break;
			}
			dp[i]=dp[j-1];
		}
	}
	cout<<dp[n];
	return 0;
}
