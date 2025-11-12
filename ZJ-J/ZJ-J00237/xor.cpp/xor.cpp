#include<bits/stdc++.h>
using namespace std;
int a[2000010],b[2000010],n,k,dp[2000010];
map<int,int>c;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
			b[1]=a[1];
		else
			b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[b[i]^k]==0)
		{
			if(b[i]==k)
				dp[i]=max(dp[i],1);
		}
		else
		{
			dp[i]=max(dp[c[b[i]^k]]+1,dp[i]);
		}
		c[b[i]]=i;
		for(int j=i;j<=n;j++)
		{
			if(dp[j]>=dp[i])
			{
				break;
			}
			else
			{
				dp[j]=dp[i];
			}
		}
	}
	cout<<dp[n];
	return 0;
}
