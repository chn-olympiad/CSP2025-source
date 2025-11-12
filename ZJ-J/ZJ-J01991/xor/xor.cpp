#include<bits/stdc++.h>
using namespace std;
int n,k,a,ans=0;
int sum[500010];//前缀和 
int dp[500010];//前i个字母的最大区间数
int f[1030*1030];//快速找t 存 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,-1,sizeof(f)); 
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum[i]=sum[i-1]^a;	
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		int t=sum[i]^k;//要在0~i 
		if(f[t]!=-1)
		{
			dp[i]=max(dp[i],f[t]+1);
		}
		f[sum[i]]=max(f[sum[i]],dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
