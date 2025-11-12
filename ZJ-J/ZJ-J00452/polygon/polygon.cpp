#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll mod=998244353;
ll n,s[5010],ans;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll a=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		a=max(a,s[i]);
	}
	if(a==1)
	{
		ll jc[5010]={},ny[5010]={},ans=0;
		jc[0]=1;
		for(int i=1;i<=5000;i++)
		{
			jc[i]=jc[i-1]*i%mod;
		}
		ny[5000]=ksm(jc[5000],mod-2);
		for(int i=4999;i>=0;i--)
		{
			ny[i]=ny[i+1]*(i+1)%mod;
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+jc[n]*ny[i]%mod*ny[n-i]%mod)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
	{
		ll ls[25],dz=0,qh=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				ls[j]=1;
			}
			else
			{
				ls[j]=0;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(ls[j]==1)
			{
				qh+=s[j+1];
				dz=max(dz,s[j+1]);
			}
		}
		if(qh>2*dz)
		{
			ans++;
		}
	}
	cout<<ans%mod;
	return 0;
}
