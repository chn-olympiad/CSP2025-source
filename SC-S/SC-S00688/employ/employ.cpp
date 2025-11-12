#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=5e2+10;
const int mod=998244353;

int n,m,ans,p[N]; string s;
int dp[20][(1<<19)];

inline void solve1()
{
	dp[0][0]=1;
	for(int i=0;i<(1<<n);++i)
	{
		int v=0;
		for(int j=1;j<=n;++j) if(i&(1<<(j-1))) ++v;
		for(int j=1;j<=n;++j)
			if(!(i&(1<<(j-1))))
				for(int k=0;k<=v;++k)
					if(s[v+1]=='0'||p[j]<=v-k)
						dp[k][i|(1<<(j-1))]=(1ll*dp[k][i|(1<<(j-1))]+dp[k][i])%mod;
					else
						dp[k+1][i|(1<<(j-1))]=(1ll*dp[k+1][i|(1<<(j-1))]+dp[k][i])%mod;
	}
	for(int i=m;i<=n;++i) ans=(1ll*ans+dp[i][(1<<n)-1])%mod;
	cout<<ans;	
}

inline void solven()
{
	for(int i=1;i<=n;++i) if(s[i]=='0') {cout<<0; return;}
	for(int i=1;i<=n;++i) if(!p[i]) {cout<<0; return;}
	ans=1;
	for(int i=1;i<=n;++i) ans=1ll*ans*i%mod;
	cout<<ans;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s; s=" "+s;
	for(int i=1;i<=n;++i) cin>>p[i];
	if(n<=18) solve1();
	else if(m==n) solven();
	else cout<<0;
	return 0;
}