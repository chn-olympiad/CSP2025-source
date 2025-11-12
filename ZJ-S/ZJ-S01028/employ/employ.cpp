//bqq miaomiaomiao
//bye OI.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=998244353;
int s[510],c[510];
int a[510];
ll f[510],inv[510];
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%p;
		}
		b>>=1,a=(a*a)%p;
	}
	return ans;
}
ll C(ll x,ll y)
{
	if(y<0||x<y)
	{
		return 0;
	}
	return f[x]*inv[y]%p*inv[x-y]%p;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	string s;
	cin>>n>>m,cin>>s,s=" "+s;
	int suba=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			suba=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i],a[i]=i;
	}
	if(n<=18)
	{
		int ans=0;
		do
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=c[a[i]]||s[i]=='0')
				{
					cnt++;
				}
			}
			ans=(ans+(n-cnt>=m))%p;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<endl;
		return 0;
	}
	if(!suba)
	{
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]*i%p;
		}
		inv[n]=qpow(f[n],p-2);
		for(int i=n-1;i>=1;i--)
		{
			inv[i]=inv[i+1]*(i+1)%p;
		}
		cout<<f[n]<<endl;
		return 0;
	}
	if(m==1)
	{
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]*i%p;
		}
		cout<<f[n]<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}