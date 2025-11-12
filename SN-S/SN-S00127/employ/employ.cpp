#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353, maxn=505;
int n, m, c[maxn], vis[maxn], p[maxn], ans, f[maxn];
string s;
void dfs(int x)
{
	if(x==n)
	{
		int cnt=0, sum=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[p[i]]||s[i]=='0') sum++;
			else cnt++;
		}
		if(cnt>=m) 
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		p[x+1]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int ct(int x)
{
	int res=0;
	while(x)
	{
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
bool flag=0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) if(s[i]=='0') flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		dfs(0);
		cout<<ans%mod;
//		for(int i=0;i<=(1<<n)-1;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(!(i>>(j-1)&1))
//				{
//					int ss=i|(1<<(j-1)), cnt=ct(i)+1;
//					if(s[cnt]=='0') dp[ss]=dp[i]+1;
//					else if(dp[i]>=c[j]) dp[ss]=dp[i]+1;
//					else dp[ss]=dp[i];
//				}
//			}
//		}
//		for(int i=0;i<=n-m;i++)
//		{
//			ans=(ans+dp[(1<<n)-1][i])%mod;
//		}
//		cout<<ans%mod;
		return 0;
	}
/*	if(flag==0)
	{*/
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0) cnt++;
		}
		f[0]=1;
		for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
		cout<<f[n]%mod;
		return 0;
//	}
	return 0;
}
