#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010,MOD=998244353;
ll n,a[N],choose[N],cnt,sum,maxx,ans;
ll fac[N],inv[N];
ll power(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b%2)
		{
			ans=ans*a%p;
		}
		a=a*a%p;
		b/=2;
	}
	return ans;
}
bool check()
{
	if(cnt>=3)
	{
		sum=0,maxx=0;
		for(int i=1;i<=cnt;i++)
		{
			sum+=choose[i];
			maxx=max(maxx,choose[i]);
		}
		return sum>maxx*2;
	}
	return false;
}
void dfs(ll u)
{
	if(u==n+1)
	{
		if(check())
		{
			ans++;
		}
		return;
	}
	choose[++cnt]=a[u];
	dfs(u+1);
	cnt--;
	dfs(u+1);
}
ll C(ll n,ll m)
{
	return fac[m]*inv[n]%MOD*inv[m-n]%MOD;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	else
	{
		fac[0]=1,inv[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=fac[i-1]*i%MOD;
			inv[i]=power(fac[i],MOD-2,MOD);
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+C(i,n))%MOD;
		}
		cout<<ans<<"\n";
	}
	return 0;
}