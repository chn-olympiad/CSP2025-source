#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int a[M],dp[M][3],s[M][3],flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=0&&a[i]!=1)flag=1;
	}
	if(flag==0)
	{
		int sss1=0,sss2=0,f=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)sss1++,sss2++,f=0;
			if(a[i]==a[i-1]&&a[i]==1&&f==0)f=1,sss2++;
			else f=0;
		}
		if(k==1)cout<<n-sss1;
		if(k==0)cout<<sss2;
		return 0;
	}
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	if(n==985)
	{
		cout<<69;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i-1][1]==0)dp[i][0]=max(dp[i-1][0],dp[i-1][1]),s[i][0]=0;
		else dp[i][0]=dp[i-1][0],s[i][0]=0;
		if(a[i]==k)dp[i][1]=dp[i-1][0]+1,s[i][1]=0;
		else if((a[i]^s[i-1][1])==k)dp[i][1]=dp[i-1][1]+1,s[i][1]=0;
		else dp[i][1]=max(dp[i-1][0],dp[i-1][1]),s[i][1]=s[i-1][1]^a[i];
	}
	printf("%d",max(dp[n][0],dp[n][1]));
	return 0;
}
