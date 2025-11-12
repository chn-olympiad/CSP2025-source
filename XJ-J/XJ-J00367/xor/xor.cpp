#include<bits/stdc++.h>
using namespace std;
int a[500005],sum,pre[500005],to[1500005],dp[500005],n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(to,-1,sizeof(to));
	to[0]=0;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	sum=sum^a[i];
	pre[i]=to[sum^k];
	to[sum]=i;
	}
	for(int i=1;i<=n;i++)
	if(pre[i]==-1)
	dp[i]=dp[i-1];
	else
	dp[i]=max(dp[i-1],dp[pre[i]]+1);
	cout<<dp[n];
	return 0;
} 
