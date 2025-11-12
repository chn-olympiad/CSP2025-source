#include<bits/stdc++.h>
#define ll long long
ll mod=998244353;
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
	}
	ll ans=0;
	for(ll i=n;i>=1;i--)
	{
		ans=(ans+i)%mod;
	}
	cout<<ans;
	return 0;
}