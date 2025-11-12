//20pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=20;
const int mod=998244353;
int n,m;
string s;
int c[maxn];
int dp[1000000][20];
int ps[1000000];
int ans;
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i)
	{
		c[i]=read();
	}
	dp[0][0]=1;
	for(int i=1;i<1<<n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(((1<<k-1)&i)==0)continue;
				int lst=i^(1<<k-1);
				ps[i]=ps[lst]+1;
				if(s[ps[i]]=='0'||c[k]<=j-1)
				{
					if(j!=0)
					{
						dp[i][j]=(dp[i][j]+dp[lst][j-1])%mod;	
					}
				}
				else if(c[k]>j)dp[i][j]=(dp[i][j]+dp[lst][j])%mod;
			}
		}
	}
	for(int i=0;i<=n-m;++i)
	{
		ans=(ans+dp[(1<<n)-1][i]);
	}
	printf("%lld",ans);
	return 0;
}
