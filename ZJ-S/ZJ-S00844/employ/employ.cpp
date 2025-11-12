#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m;
int s[525],a[525],c[525];
ll dp[525][525];
void solve1()
{
	if(c[1]==0)
	{
		cout<<0<<'\n';
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)
		{
			cout<<0<<'\n';
			exit(0);
		}
	}
	ll sum=1;
	for(int i=1;i<=n;i++) 
	{
		sum*=i;
		sum%=mod;
	}
	
	cout<<sum<<'\n';
	
	exit(0);
}
void solve2()
{
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		cout<<0<<'\n';
		exit(0);
	}
	ll sum=1,ans=0;
	
	for(int i=1;i<=n;i++)
	{
//		if(i-a[i]<c[i])
//		{
			sum=1;
			for(int j=1;j<=n-c[i];j++) sum*=j;
			ans=(ans+(sum*a[c[i]]%mod))%mod;
//		}
	}
	
	cout<<ans<<'\n';
	
	exit(0);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ss;
		cin>>ss;
		s[i]=(ss-'0');
		a[i]+=(s[i]^1);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	sort(c+1,c+1+n);
	if(m==n) solve1();
	else if(m==1) solve2(); 
	
	dp[0][0]=1ll*1;
	for(int i=1;i<=n;i++)//第i人 
	{
		for(int j=0;j<i;j++)//已经录取j个 
		{
			dp[i][j]=dp[i-1][j];
			if((i-1-j+1)<c[i])
			{
				dp[i][j+1]=(dp[i][j]+1ll*dp[i-1][j-1]*(i-j+2)%mod)%mod;
			}
		}
	}
	
	ll sum=0;
	for(int i=n;i>=m;i--) sum=(sum+dp[n][i])%mod;
	cout<<sum<<'\n';
	
	return 0;
}
