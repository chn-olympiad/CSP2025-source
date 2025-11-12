#include<bits/stdc++.h>
#define ll long long
using namespace std;
//char c;
ll mod=998244353;
ll a[5050];
ll g[5050];
ll n;
ll mp[5005][5005]={0};
//char d;
ll f(int m,int k)
{
	ll r=n,l=1;
	ll p=upper_bound(mp[k]+1,mp[k]+n+1,m)-mp[k];
	return p;
}
ll ksm(int x,int y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
		{
			t=(t*x)%mod;//
		}
		x=(x*x%mod)%mod;//
		y=y>>1;
	}
	return t%mod;
}
ll C(int n,int m)
{
	if(n==m)
	{
		return 1;
	}
	//return (g[n])*(ksm(g[m],mod-2))/g[n-m];
	//cout<<(ksm(2,mod-2));
	return ((g[n]%mod)*((ksm(g[m],mod-2)%mod)%mod)*(ksm(g[n-m],mod-2))%mod)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	g[0]=1;
	for(ll i=1;i<=n;i++)
	{
		g[i]=(g[i-1]%mod*i%mod)%mod;
		//cout<<g[i];
	}
	//cout<<C(3,2);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		ll ans=0;
		ans=a[i];
		for(ll j=i+1;j<=n;j++)
		{
			ans+=a[j];
			mp[j-i+1][min((ll)5001,ans)]=i;
			//cout<<j-i+1<<" "<<ans<<" "<<i<<'\n';
		}
	}
	for(ll i=n;i>=3;i--)
	{
		for(ll j=2;j<i;j++)
		{
			ll m=a[i]+1,p=0;
			while(m<=5001)
			{
				if(mp[j][m])
				{
					p=mp[j][m];
					break;
				}
				m++;
			}
			if(p==0||p+j>=i)
			{
				continue;
			}
			else
			{
				//cout<<p;
				ans=(ans+C(i-p,j)%mod)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}