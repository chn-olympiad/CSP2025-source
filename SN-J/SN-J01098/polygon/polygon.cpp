//SN-J01098  陈和骏  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010,mod=998244353;
int a[N],dp[N][N];
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=rd(),maxx=0,ans=0;
	for(int i=1;i<=n;i++) a[i]=rd(),maxx=max(maxx,a[i]+1);
	dp[0][0]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=maxx;j++)
		{
			ans=(ans+dp[i-1][j])%mod;
		}
		dp[i][maxx]=dp[i-1][maxx]*2%mod;
		for(int j=0;j<maxx;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			dp[i][min(maxx,j+a[i])]=(dp[i][min(maxx,j+a[i])]+dp[i-1][j])%mod;
		}
	}
	write(ans);
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/
