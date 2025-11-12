#include<bits/stdc++.h>
using namespace std;
int sum[500010],a[500010];
int lst[3000010],dp[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	memset(dp,-0x3f,sizeof(dp));
	memset(lst,-0x3f,sizeof(lst));
	lst[0]=0;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1],lst[sum[i]^k]+1);
		lst[sum[i]]=max(lst[sum[i]],dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
