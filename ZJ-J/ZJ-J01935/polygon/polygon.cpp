#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5001],dp[5001];
long long ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n<3)
	{
		printf("0\n");
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	int m=0;
	for(int i=1;i<n;i++)
	{
		int x;
		for(int k=m;k>=0;k--)
		{
			x=k+a[i];
			if(x<=5000) dp[x]=(dp[x]+dp[k])%Mod;
			else dp[5001]=(dp[5001]+dp[k])%Mod;
			if(x>a[i+1]) ans=(ans+dp[x])%Mod;
		}
		dp[a[i]]=(dp[a[i]]+1)%Mod;
		m=min(m+a[i],5000);
	}
	printf("%d\n",ans);
	return 0;
}
