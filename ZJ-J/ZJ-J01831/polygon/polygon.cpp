#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,dp[5005];
int dfs(int x,int y)
{
	int jia=0;
	if(y==-1)
	{
		jia=1;
		for(int i=1;i<x;i++)
		{
			jia=(jia*2)%998244353;
		}
		return jia;
	}
	int dai=upper_bound(dp+1,dp+x+1,y)-dp;
	for(int j=dai;j<x;j++)
	{
		jia=(jia+dfs(j,max(y-a[j],-1)))%998244353;
	}
	return jia;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i-1]+a[i])%998244353;
	}
	for(int i=3;i<=n;i++)
	{
		ans=(ans+dfs(i,a[i]))%998244353;
	}
	printf("%d",ans);
	return 0;
}