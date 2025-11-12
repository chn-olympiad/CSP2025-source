#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n;
int a[maxn];
int dp[50005];
int ans;
int p;
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	p+=a[1];
	dp[0]=1;
	for(int i=1;i<n;++i)
	{
		p+=a[i+1];
		for(int k=p;k>=a[i];--k)
		{
			dp[k]=(dp[k]+dp[k-a[i]])%mod;
		}
		for(int j=a[i+1]+1;j<=p-a[i+1];++j)ans=(ans+dp[j])%mod;
	}
	printf("%lld",ans);
	return 0;
}

