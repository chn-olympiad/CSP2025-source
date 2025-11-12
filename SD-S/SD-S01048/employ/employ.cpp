#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=500;
int n,m;
string s;
int c[N+5];
int vis=0;
bool flag=0;
ll ans=0;
int dp[20][1<<20];
int temp[N+5],cnt=0;
ll dfs(int now)
{
	if(vis+1==(1<<n))
	{
		return n-now>=m;
	}
	if(dp[now][vis]==-1)
	{
		ll res=0;
		for(int i=0;i<n;i++)
		{
			if((vis>>i)&1) continue;
			vis^=(1<<i);cnt++;
			if(now>=c[i]||s[cnt-1]=='0') res=(res+dfs(now+1))%mod;
			else res=(res+dfs(now))%mod;
			vis^=(1<<i);cnt--;
		}
		dp[now][vis]=res;
	}
	return dp[now][vis];
}
signed main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') flag=1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	if(flag==0&&n>18)
	{
		ans=1;
		for(int i=0;i<n;i++)
		{
			if(c[i]==0) cnt++;
			ans=ans*i%mod;
		}
		if(n-cnt>=m) cout<<ans<<"\n";
		else cout<<0<<"\n";
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0)<<"\n";
	return 0;
}
