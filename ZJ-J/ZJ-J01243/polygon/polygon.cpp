#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998224353;
const ll N=5005;
ll n,ans;
ll c(ll n,ll m)
{
	ll t1=1,t2=2;
	for(ll i=1,j=m;i<=n,j>=1;i++,j--) t1=(t1*j)%mod;
	for(ll i=1;i<=m;i++) t2=(t2*i)%mod;
	return t1/t2;
}
ll a(ll n)
{
	ll t;
	for(ll i=1;i<=n;i++) t=(t*i)%mod;
	return t;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=3;i<=n;i++)
	{
		ll t=c(n,i);
		ans=(ans+a(t))%mod;
	}cout<<ans;
	return 0;
}